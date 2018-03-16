
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
	Token_stream();                 //��������
	Token get();                    //ȡtoken����
	void putback(Token t);          //��token�Ż�����
	void ignore(char c);            
private:
	bool full;                      //���еĻ���״̬
	Token buffer;                   //������
};
