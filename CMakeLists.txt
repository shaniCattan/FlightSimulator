cmake_minimum_required(VERSION 3.15)
project(ex3)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS -pthread)

add_executable(ex3 main.cpp Command.cpp Command.h ConnectCommand.cpp
        ConnectCommand.h DefineVarCommand.cpp DefineVarCommand.h IfCommand.cpp IfCommand.h Lexer.cpp Lexer.h
        OpenServerCommand.cpp OpenServerCommand.h Parser.cpp Parser.h PrintCommand.cpp PrintCommand.h Sleep.cpp
        Sleep.h VarEqual.cpp VarEqual.h VarIn.cpp VarIn.h VarOut.cpp VarOut.h VarSuper.h WhileCommand.cpp WhileCommand.h
      Expression.h BinaryOperator.h Plus.h Plus.cpp Minus.cpp Minus.h Mul.cpp Mul.h Div.cpp Div.h Value.h Value.cpp
        UnaryOperator.h UPlus.h UPlus.cpp UMinus.h UMinus.cpp Variable.h Variable.cpp Interpreter.h Interpreter.cpp
        Boolean.cpp Boolean.h ConditionParser.cpp ConditionParser.h SocketReader.cpp SocketReader.h)
