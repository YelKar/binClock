namespace clock {
  class Arrow {
  private:
    int clk, ltch, ser;
  public:
    Arrow(int clockPin, int latchPin, int dataPin);
    void set(int value);
    void open();
    void close();
  };
  class Clock {
    public:
      Arrow *hour, *minute, *second;
      Clock(Arrow *h, Arrow *m, Arrow *s);
      void set(int h, int m, int s);
      void open();
      void close();
  };
};
clock::Arrow::Arrow(int clockPin, int latchPin, int dataPin) {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  clk = clockPin, ltch = latchPin, ser = dataPin;
}

void clock::Arrow::set(int value) {
  shiftOut(ser, clk, LSBFIRST, value);
}
void clock::Arrow::open() {
  digitalWrite(ltch, LOW);
}
void clock::Arrow::close() {
  digitalWrite(ltch, HIGH);
}

clock::Clock::Clock(Arrow *h, Arrow *m, Arrow *s) {
  hour = h;
  minute = m;
  second = s;
}
void clock::Clock::set(int h, int m, int s) {
  second -> set(s);
  minute -> set(m);
  hour -> set(h);
}
void clock::Clock::open() {
  hour->open();
}
void clock::Clock::close() {
  hour->close();
}
