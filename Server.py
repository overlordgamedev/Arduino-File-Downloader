import base64

from flask import Flask

app = Flask(__name__)

# Путь до файла который нужно подкачивать
input_path = "C:\\Users\\overl\\Desktop\\ArduinoDownloader\\Soft.zip"

# Чтение файла в бинарном режиме
with open(input_path, 'rb') as file:
    file_bytes = file.read()

# Конвертация байтов в Base64
file_base64 = base64.b64encode(file_bytes)

# Отображение байтов файла на веб странице. Это нужно для того что бы ардуино зашел на страницу и скопировал эти байты
@app.route('/')
def index():
    return file_base64

if __name__ == '__main__':
    app.run(host="0.0.0.0", port="1488", debug=True)
