#include <Keyboard.h> 
/*
 * Developer @root_haxor !
 */

// Init function
void setup()
{
  // Begining the stream
  Keyboard.begin();

  // Waiting 500ms for init
  delay(500);

  // This is a script to download and change the wallpaper in windows 10
  // In order to work, windows must be using the default app for opening photos
  delay(5000);

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ESC);
  Keyboard.releaseAll();

  delay(100);

  // Note: The internet explorer method works usually for everyone but
  // If you want to use Chrome or Firefox instead of IE, remove 'iexplorer' from the following line
  // but also make sure to follow instructions bellow
  Keyboard.print("iexplore http://www.thecuriosityworkshop.com/wp-content/uploads/2015/03/01-rubberduck-hongkong.jpg");

  typeKey(KEY_RETURN);

  delay(4000);

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(115);
  Keyboard.releaseAll();

  delay(2000);

  typeKey(KEY_RETURN);

  delay(300);

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ESC);
  Keyboard.releaseAll();

  delay(300);

  // If you want to use Chrome, change 'Documents' to 'Downloads'
  // If you want to use Firefox, change 'Documents' to 'Pictures'
  Keyboard.print("%USERPROFILE%\\Documents\\01-rubberduck-hongkong.jpg");

  delay(500);

  typeKey(KEY_RETURN);

  delay(500);

  typeKey(KEY_TAB);

  delay(500);

  typeKey(KEY_TAB);

  delay(500);

  typeKey(KEY_TAB);

  delay(500);

  typeKey(KEY_TAB);

  delay(500);

  typeKey(KEY_TAB);

  delay(500);

  typeKey(KEY_TAB);

  delay(500);

  typeKey(KEY_TAB);

  delay(500);

  typeKey(KEY_RETURN);

  delay(500);

  typeKey(KEY_DOWN_ARROW);

  delay(500);

  typeKey(KEY_DOWN_ARROW);

  delay(500);

  typeKey(KEY_DOWN_ARROW);

  delay(500);

  typeKey(KEY_DOWN_ARROW);

  delay(500);

  typeKey(KEY_RETURN);

  delay(500);

  typeKey(KEY_DOWN_ARROW);

  delay(500);

  typeKey(KEY_DOWN_ARROW);

  delay(500);

  typeKey(KEY_RETURN);

  delay(500);
}

void typeKey(int key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

// Unused
void loop() {}
