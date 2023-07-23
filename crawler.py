import requests, re, json

data = []

max_page = 1578945
for i in range(3600):
    r = requests.get("https://rasekhoon.net/faq/show/" + str(i), headers={'Accept': 'application/json'})
    content = r.content.decode("utf-8")
    
    print(str(i) + " / " + str(max_page))
    
    if "name\": \"پرسش و پاسخ راسخون" in content:
    
        print("Good Page")
        
        content = r.content.decode("utf-8")

        question_index = content.find("<b>پرسش :</b>")
        question_block = content[question_index : question_index + 101]
        question = question_block[question_block.find("<h2>") + 4 : question_block.find("</h2>")]
        question = question.replace("\u200c", "")
        question = question.replace("\u200e", "")

        response_block = content[content.find("<b>پاسخ :</b>") : content.find("</article>")]
        response = response_block[response_block.find("<br />") : response_block.find("</article>")]
        response = re.sub('\<.{1,7}\>', '', response)
        response = re.sub('\<span.*', '', response)
        response = re.sub('\-{2,}', '', response)
        response = response.replace("منبع: ", "")
        response = response.replace("zanjani.net", "")
        response = response.replace("\u200c", "")
        response = response.replace("\u200e", "")
        response = re.sub('\s{2,}', ' ', response)

        row = {}
        row["instruction"] = question
        row["input"] = ""
        row["output"] = response

        data.append(row)

with open("./rasekhoon.json", "w", encoding="utf-8") as file:
    json.dump(data, file, ensure_ascii=False)
