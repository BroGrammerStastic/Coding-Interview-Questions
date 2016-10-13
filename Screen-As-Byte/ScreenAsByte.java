import java.util.Arrays;

public class ScreenAsBytes {

  public static void setPixel(byte[] screen, int width, int x, int y) {
    // TODO complete this code
    /*
      - This method when called, will set the byte to 1 at the right location
      - We pass the screen to update the screen with the new value
      - We call another method to retrieve the specific byte at x row
      - We then call another nested method which will the Yth row for us
    */
    _setByteTo1(
      screen,
      _getSpecificByteAtXRow(
        _getByteAtGivenRow(width,y),
        x),
      x
    );

  }

  /*
    - This method will split 16 binary by two, so multiple of 8 binary numbers
  */
  public static int _getByteAtGivenRow(int width, int YthRow) {
    int splitXRowIntoTwo = width / 8; // returns 2 if width is 16
    return splitXRowIntoTwo * YthRow;
  }

  /*
    - This method will get the specific byte at row x
  */
  public static int _getSpecificByteAtXRow(int ythRow,int xValue) {
    int getX = xValue / 8;
    int getByte = ythRow + getX;
    return getByte;
  }

  /*
    - This method will chnage the value to 1
    - We take the x value and do a modulus by 8 to give the remainder
    - Since bytes are read from right to left. We gonna make it read from left to right
    - Do a pow and add it to the given byte at row x
    - initialise the screen at given index in row x with the new value
    -
  */
  public static void _setByteTo1(byte[] screen, int getSpecificByteAtXRow, int getX) {
    int getRemainder = getX % 8;
    double readFromLeftToRight = 7 - getRemainder;
    double MathPow = Math.pow(2,readFromLeftToRight);
    double getByteInScreen = screen[getSpecificByteAtXRow] + MathPow;
    screen[getSpecificByteAtXRow] = (byte) getByteInScreen;
  }


  /*
    - A simple for loop  that sets the pixel started from x index til the end of x
  */
  public static void drawHorizontalLine(byte[] screen, int width, int startX, int endX, int y) {
    // TODO complete this code
    for (int i = startX; i <= endX ; i++) {
      setPixel(
        screen,
        width,
        i,
        y
      );
    }
  }

  /*
    - Like drawHorizontalLine method above, we use the same idea, but instead of
    - looping from x index, we loop from y index till the end of y index
  */
  public static void drawVerticalLine(byte[] screen, int width, int x, int startY, int endY) {
    // TODO complete this code
    for (int i = startY; i <= endY ; i++) {
      setPixel(
        screen,
        width,
        x,
        i
      );
    }
  }

  /*
    - This method is not used, but helped me at first stage.
    - this method, when called, will replace the char with the new value
  */
  public static String changeCharInPosition(int position, char ch, String str) {
    char[] charArray = str.toCharArray();
    charArray[position] = ch;
    return new String(charArray);
  }

  /*
    - This method converts given hex value to binary
  */
  public static byte[] _callingHexToByteArray(String hexString) {
    int _HexStringLength = hexString.length();
    byte[] newByte = new byte[_HexStringLength / 2];
    for (int i = 0; i < _HexStringLength; i += 2) {
      int shift = (Character.digit(hexString.charAt(i), 16) << 4);
      int padd = Character.digit(hexString.charAt( i + 1 ), 16);
      newByte[i / 2] = (byte) (shift + padd);
    }
    return newByte;
  }

}
