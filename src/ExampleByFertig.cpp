#include <iostream>

using std::cout;
using std::endl;

void printHeader() {
   cout << endl;
   cout << "===============================================" << endl;
   cout << "    CppCon 2022 - Lecture by Andreas Fertig    " << endl;   
   cout << "      Back to Basics: C++ Move Semantics       " << endl;
   cout << "          Perfect Forwarding Example           " << endl;
   cout << "===============================================" << endl;
   cout << endl;
}

struct Apple {
   Apple( const std::string & s ) {
      std::cout << "lvalue: " << s << std::endl;
   }

    Apple( const std::string && s ) noexcept {
      std::cout << "rvalue: " << s << std::endl;
   }
};

template <typename T, typename U>
auto make( U && value ) {
   return T{ std::forward<U>( value ) };
}

int main(int argc, char *argv[]) {
   printHeader();

   std::string str{ "Hello" };

   Apple red{ make<Apple>(str) };
   Apple green{ make<Apple>(std::string{"World"}) };


   return 0;
}
