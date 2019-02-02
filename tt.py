import requests

url = "www.baidu.com"
html = requests.get(url)
print(html.text)