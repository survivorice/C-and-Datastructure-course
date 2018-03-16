
class Token {                  //make a token
  public:
	char kind;
	double value;
	Token(char ch):                 //token no value
		kind(ch), value(0) {}
	Token(char ch, double val):     //token with value
		kind(ch), value(val) {}
};


class Token_stream { 
public:
	Token_stream();                 //构建函数
	Token get();                    //取token函数
	void putback(Token t);          //将token放回流中
	void ignore(char c);            
private:
	bool full;                      //流中的缓存状态
	Token buffer;                   //缓存区
};
