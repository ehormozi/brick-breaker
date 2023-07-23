import requests, re, json

page_number = 1
max_page = 12090
base_url = "https://rasekhoon.net/faq/page"
data = []
while page_number <= 10:
    
    print("page: " + str(page_number))
    
    meta_r = requests.get(base_url + str(page_number))
    meta_content = meta_r.content.decode("utf-8")
    
    urls = []
    if "<div class=\"w-100 ArticleGroupList GroupListThumbnail row mx-0\">" in meta_content:
        meta_content = meta_content[meta_content.find("<div class=\"w-100 ArticleGroupList GroupListThumbnail row mx-0\">") : ]
        meta_content = meta_content[ : meta_content.find("<div class=\"js_pagination col-12 d-flex my-5\">")]
        
        while "<section class=\"ArticleGroupItem col-12 px-xs-1 mt-3 pt-3 ShiningOver\">" in meta_content:
            url = "https://rasekhoon.net" + meta_content[meta_content.find("/faq/show/") : meta_content.find("\" title=\"")]
            urls.append(url)
            meta_content = meta_content[meta_content.find("</section>") + len("</section>") : ]
    
    question_counter = 1
    for url in urls:

        print("Question : " + str(question_counter))
        question_counter += 1

        r = requests.get(url, headers={'Accept': 'application/json'})
        content = r.content.decode("utf-8")
        
        question_block = content[content.find("<b>پرسش :</b>") : ]
        question_block = question_block[ : question_block.find("</div>")]
        question = question_block[question_block.find("<h2>") + 4 : question_block.find("</h2>")]
        question = question.replace("\u200c", "")
        question = question.replace("\u200e", "")
        question = question.replace("\u00a0", "")
        question = question.replace("\u200f", "")
        question = re.sub('\s{2,}', ' ', question)
        
        response_block = content[content.find("<b>پاسخ :</b>") : content.find("</article>")]
        response = response_block[response_block.find("<br />") : response_block.find("</article>")]
        response = re.sub('\<.{1,7}\>', '', response)
        response = re.sub('\<span.*', '', response)
        response = re.sub('\-{2,}', '', response)
        response = response.replace("منبع: ", "")
        response = response.replace("zanjani.net", "")
        response = response.replace("\u200c", "")
        response = response.replace("\u200e", "")
        response = response.replace("\u00a0", "")
        response = response.replace("\u200f", "")
        response = re.sub('\s{2,}', ' ', response)
        
        row = {}
        row["instruction"] = question
        row["input"] = ""
        row["output"] = response
        data.append(row)
    
    page_number += 1

with open("./data.json", "w", encoding="utf-8") as data_file:
    json.dump(data, data_file, ensure_ascii=False)
