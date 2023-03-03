import java.io.*;
import java.util.*;

public class Main implements Runnable {
  private static void solve() {

  }

  private static class IntegerPair implements Comparable<IntegerPair> {
    Integer _first, _second;
  
    public IntegerPair(Integer f, Integer s) {
      _first = f;
      _second = s;
    }
  
    public int compareTo(IntegerPair o) {
      if (!this.first().equals(o.first()))
        return this.first() - o.first();
      else
        return this.second() - o.second();
    }
  
    Integer first() { return _first; }
    Integer second() { return _second; }
  }
  /** Template starts: */
  @Override
  public void run() {
    solve();
    out.flush();
    System.exit(0);
  }

  private final static InputReader in = new InputReader(System.in);
  private final static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

  public static void main(String[] args) {
    new Thread(null, new Main(), "Main", 1 << 26).start();
  }

  private static class InputReader {
    private final InputStream stream;
    private final byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;

    InputReader(InputStream stream) {
      this.stream = stream;
    }

    private byte read() {
      if (numChars == -1) {
        throw new InputMismatchException("EOF has been reached");
      }
      if (curChar >= numChars) {
        curChar = 0;
        try {
          numChars = stream.read(buf);
        } catch (IOException e) {
          throw new InputMismatchException();
        }
        if (numChars <= 0)
          return -1;
      }
      return buf[curChar++];
    }

    int readInt() {
      byte c = read();
      while (isWhitespace(c)) {
        c = read();
      }
      if (isEOF(c)) {
        throw new InputMismatchException("EOF has been reached");
      }

      int sgn = 1;
      if (c == '-') {
        sgn = -1;
        c = read();
      }
      int res = 0;
      do {
        if (c < '0' || c > '9') {
          throw new InputMismatchException();
        }
        if (res > Integer.MAX_VALUE / 10) {
          throw new InputMismatchException("Input is not an integer");
        }
        res *= 10;
        int d = c - '0';
        if (res > Integer.MAX_VALUE - d) {
          throw new InputMismatchException("Input is not an integer");
        }
        res += d;
        c = read();
      } while (!isWhitespaceOrEOF(c));
      return res * sgn;
    }

    long readLong() {
      byte c = read();
      while (isWhitespace(c)) {
        c = read();
      }
      if (isEOF(c)) {
        throw new InputMismatchException("EOF has been reached");
      }

      int sgn = 1;
      if (c == '-') {
        sgn = -1;
        c = read();
      }
      long res = 0;
      do {
        if (c < '0' || c > '9') {
          throw new InputMismatchException();
        }
        if (res > Long.MAX_VALUE / 10) {
          throw new InputMismatchException("Input is not a long integer");
        }
        res *= 10;
        int d = c - '0';
        if (res > Long.MAX_VALUE - d) {
          throw new InputMismatchException("Input is not a long integer");
        }
        res += d;
        c = read();
      } while (!isWhitespaceOrEOF(c));
      return res * sgn;
    }

    String readString() {
      byte c = read();
      while (isWhitespace(c)) {
        c = read();
      }
      if (isEOF(c)) {
        return null;
      }

      StringBuilder res = new StringBuilder();
      do {
        if (Character.isValidCodePoint(c)) {
          res.appendCodePoint(c);
        }
        c = read();
      } while (!isWhitespaceOrEOF(c));
      return res.toString();
    }

    private boolean isWhitespace(byte c) {
      return c == ' ' || c == '\n' || c == '\r' || c == '\t';
    }

    private boolean isEOF(byte c) {
      return c == -1;
    }

    private boolean isWhitespaceOrEOF(byte c) {
      return isWhitespace(c) || isEOF(c);
    }
  }
}