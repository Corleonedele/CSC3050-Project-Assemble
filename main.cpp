#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <QCoreApplication>

using namespace std;

int CheckRegister(string r){
    if (r == "$zero"){return 0;}
    else if (r == "$at"){return 1;}
    else if (r == "$v0"){return 2;}
    else if (r == "$v1"){return 3;}
    else if (r == "$a0"){return 4;}
    else if (r == "$a1"){return 5;}
    else if (r == "$a2"){return 6;}
    else if (r == "$a3"){return 7;}
    else if (r == "$t0"){return 8;}
    else if (r == "$t1"){return 9;}
    else if (r == "$t2"){return 10;}
    else if (r == "$t3"){return 11;}
    else if (r == "$t4"){return 12;}
    else if (r == "$t5"){return 13;}
    else if (r == "$t6"){return 14;}
    else if (r == "$t7"){return 15;}
    else if (r == "$s0"){return 16;}
    else if (r == "$s1"){return 17;}
    else if (r == "$s2"){return 18;}
    else if (r == "$s3"){return 19;}
    else if (r == "$s4"){return 20;}
    else if (r == "$s5"){return 21;}
    else if (r == "$s6"){return 22;}
    else if (r == "$s7"){return 23;}
    else if (r == "$t8"){return 24;}
    else if (r == "$t9"){return 25;}
    else if (r == "$k0"){return 26;}
    else if (r == "$k1"){return 27;}
    else if (r == "$gp"){return 28;}
    else if (r == "$sp"){return 29;}
    else if (r == "$fp"){return 30;}
    else if (r == "$ra"){return 31;}
    else{return -1;}
}

string GetOffset(string address){
    string offset;
    int f = address.find("(");
    offset = address.substr(0, f);
    return offset;
}

string GetBase(string address){
    string base;
    int f = address.find("(");
    int l = address.find(")");
    base = address.substr(f + 1, l - f - 1);
    return base;
}

string ToBinary(int num, int index){
    string binary = "";
    for (int i = 0; i < index; i++) {
        if(num % 2 == 0){
            binary += "0";
            num = num / 2;
        }else{
            binary += "1";
            num = (num - 1) / 2;
        }
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

string ToDecimal(string num){
    string tem;
    return tem;
}



string _add(string rd, string rs, string rt){
    string _rd = ToBinary(CheckRegister(rd), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _rt = ToBinary(CheckRegister(rt), 5);
    return "000000" + _rs + _rt + _rd + "00000" + "100000";
}

string _addu(string rd, string rs, string rt){
    string _rd = ToBinary(CheckRegister(rd), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _rt = ToBinary(CheckRegister(rt), 5);
    return "000000" + _rs + _rt + _rd + "00000" + "100001";
}

string _addi(string rt, string rs, string imm){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _imm = ToBinary(stoi(imm), 16);
    return "001000" + _rs + _rt + _imm;
}

string _addiu(string rt, string rs, string imm){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _imm = ToBinary(stoi(imm), 16);
    return "001001" + _rs + _rt + _imm;
}

string _and(string rd, string rs, string rt){
    string _rd = ToBinary(CheckRegister(rd), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _rt = ToBinary(CheckRegister(rt), 5);
    return "000000" + _rs + _rt + _rd + "00000" + "100100";
}

string _andi(string rt, string rs, string imm){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _imm = ToBinary(stoi(imm), 16);
    return "001100" + _rs + _rt + _imm;
}

string _clo(string rd, string rs){
    string _rd = ToBinary(CheckRegister(rd), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    return "011100" + _rs + "00000" + _rd + "00000" + "100001";
}

string _clz(string rd, string rs){
    string _rd = ToBinary(CheckRegister(rd), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    return "011100" + _rs + "00000" + _rd + "00000" + "100000";
}

string _div(string rs, string rt){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    return "000000" + _rs + _rt + "00000" + "00000" + "011010";
}

string _divu(string rs, string rt){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    return "000000" + _rs + _rt + "00000" + "00000" + "011011";
}

string _mult(string rs, string rt){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    return "000000" + _rs + _rt + "00000" + "00000" + "011000";
}

string _multu(string rs, string rt){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    return "000000" + _rs + _rt + "00000" + "00000" + "011001";
}

string _mul(string rd, string rs, string rt){
    string _rd = ToBinary(CheckRegister(rd), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _rt = ToBinary(CheckRegister(rt), 5);
    return "011100" + _rs + _rt + _rd + "00000" + "000010";
}

string _madd(string rs, string rt){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    return "011100" + _rs + _rt + "00000" + "00000" + "000000";
}

string _maddu(string rs, string rt){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    return "011100" + _rs + _rt + "00000" + "00000" + "000001";
}

string _msub(string rs, string rt){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    return "011100" + _rs + _rt + "00000" + "00000" + "000100";
}

string _msubu(string rs, string rt){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    return "011100" + _rs + _rt + "00000" + "00000" + "000101";
}

string _nor(string rd, string rs, string rt){
    string _rd = ToBinary(CheckRegister(rd), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _rt = ToBinary(CheckRegister(rt), 5);
    return "000000" + _rs + _rt + _rd + "00000" + "100111";
}

string _or(string rd, string rs, string rt){
    string _rd = ToBinary(CheckRegister(rd), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _rt = ToBinary(CheckRegister(rt), 5);
    return "000000" + _rs + _rt + _rd + "00000" + "100101";
}

string _ori(string rt, string rs, string imm){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _imm = ToBinary(stoi(imm), 16);
    return "001101" + _rs + _rt + _imm;
}

string _sll(string rd, string rt, string shamt){ // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _rd = ToBinary(CheckRegister(rd), 5);
    string _shamt = ToBinary(stoi(shamt), 5);
    return "00000000000" + _rt + _rd + _shamt + "000000";
}

string _sllv(string rd, string rt, string rs){
    string _rd = ToBinary(CheckRegister(rd), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _rt = ToBinary(CheckRegister(rt), 5);
    return "000000" + _rs + _rt + _rd + "00000" + "000100";
}

string _sra(string rd, string rt, string shamt){ // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _rd = ToBinary(CheckRegister(rd), 5);
    string _shamt = ToBinary(stoi(shamt), 5);
    return "00000000000" + _rt + _rd + _shamt + "000011";
}

string _srav(string rd, string rt, string rs){
    string _rd = ToBinary(CheckRegister(rd), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _rt = ToBinary(CheckRegister(rt), 5);
    return "000000" + _rs + _rt + _rd + "00000" + "000111";
}

string _srl(string rd, string rt, string shamt){ // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _rd = ToBinary(CheckRegister(rd), 5);
    string _shamt = ToBinary(stoi(shamt), 5);
    return "00000000000" + _rt + _rd + _shamt + "000010";
}

string _srlv(string rd, string rt, string rs){
    string _rd = ToBinary(CheckRegister(rd), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _rt = ToBinary(CheckRegister(rt), 5);
    return "000000" + _rs + _rt + _rd + "00000" + "000110";
}

string _sub(string rd, string rs, string rt){
    string _rd = ToBinary(CheckRegister(rd), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _rt = ToBinary(CheckRegister(rt), 5);
    return "000000" + _rs + _rt + _rd + "00000" + "100010";
}

string _subu(string rd, string rs, string rt){
    string _rd = ToBinary(CheckRegister(rd), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _rt = ToBinary(CheckRegister(rt), 5);
    return "000000" + _rs + _rt + _rd + "00000" + "100011";
}

string _xor(string rd, string rs, string rt){
    string _rd = ToBinary(CheckRegister(rd), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _rt = ToBinary(CheckRegister(rt), 5);
    return "000000" + _rs + _rt + _rd + "00000" + "100110";
}

string _xori(string rt, string rs, string imm){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _imm = ToBinary(stoi(imm), 16);
    return "001110" + _rs + _rt + _imm;
}

string _lui(string rt, string imm){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _imm = ToBinary(stoi(imm), 16);
    return "00111100000" + _rt + _imm;
}

string _slt(string rd, string rs, string rt){
    string _rd = ToBinary(CheckRegister(rd), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _rt = ToBinary(CheckRegister(rt), 5);
    return "000000" + _rs + _rt + _rd + "00000" + "101010";
}

string _sltu(string rd, string rs, string rt){
    string _rd = ToBinary(CheckRegister(rd), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _rt = ToBinary(CheckRegister(rt), 5);
    return "000000" + _rs + _rt + _rd + "00000" + "101011";
}

string _slti(string rt, string rs, string imm){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _imm = ToBinary(stoi(imm), 16);
    return "001010" + _rs + _rt + _imm;
}

string _sltiu(string rt, string rs, string imm){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _imm = ToBinary(stoi(imm), 16);
    return "001011" + _rs + _rt + _imm;
}


string _beq(string rs, string rt, string label){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _offset = ToBinary((stoi(label) ), 16);
    return "000100" + _rs + _rt + _offset;
}

string _bgez(string rs, string label){
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _offset = ToBinary((stoi(label)), 16);
    return "000001" + _rs + "00001" + _offset;
}

string _bgezal(string rs, string label){
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _offset = ToBinary(stoi(label), 16);
    return "000001" + _rs + "10001" + _offset;
}

string _bgtz(string rs, string label){
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _offset = ToBinary(stoi(label), 16);
    return "000111" + _rs + "00000" + _offset;
}

string _blez(string rs, string label){
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _offset = ToBinary(stoi(label), 16);
    return "000110" + _rs + "00000" + _offset;
}

string _bltzal(string rs, string label){
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _offset = ToBinary(stoi(label), 16);
    return "000001" + _rs + "10000" + _offset;
}

string _bltz(string rs, string label){
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _offset = ToBinary(stoi(label), 16);
    return "000001" + _rs + "00000" + _offset;
}

string _bne(string rs, string rt, string label){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _offset = ToBinary(stoi(label), 16);
    return "000101" + _rs + _rt + _offset;
}

string _j(string target){
    string _target = ToBinary(stoi(target), 26);
    return "000010" + _target;
}

string _jal(string target){
    string _target = ToBinary(stoi(target), 26);
    return "000011" + _target;
}

string _jalr(string rs, string rd){
    string _rd = ToBinary(CheckRegister(rd), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    return "000000" + _rs + "00000" + _rd + "00000" + "001001";
}

string _jr(string rs){
    string _rs = ToBinary(CheckRegister(rs), 5);
    return "000000" + _rs + "000000000000000" + "001000";
}

string _teq(string rs, string rt){// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    return "000000" + _rs + _rt + "0000000000" + "110100";
}

string _teqi(string rs, string imm){// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _imm = ToBinary(stoi(imm), 16);
    return "000001" + _rs + "01100" + _imm;
}

string _tne(string rs, string rt){// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    return "000000" + _rs + _rt + "0000000000" + "110110";
}

string _tnei(string rs, string imm){// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _imm = ToBinary(stoi(imm), 16);
    return "000001" + _rs + "001110" + _imm;
}

string _tge(string rs, string rt){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    return "000000" + _rs + _rt + "0000000000" + "110000";
}

string _tgeu(string rs, string rt){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    return "000000" + _rs + _rt + "0000000000" + "110001";
}

string _tgei(string rs, string imm){
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _imm = ToBinary(stoi(imm), 16);
    return "000001" + _rs + "001000" + _imm;
}

string _tgeiu(string rs, string imm){
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _imm = ToBinary(stoi(imm), 16);
    return "000001" + _rs + "001001" + _imm;
}

string _tlt(string rs, string rt){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    return "000000" + _rs + _rt + "0000000000" + "110010";
}

string _tltu(string rs, string rt){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _rs = ToBinary(CheckRegister(rs), 5);
    return "000000" + _rs + _rt + "0000000000" + "110011";
}

string _tlti(string rs, string imm){
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _imm = ToBinary(stoi(imm), 16);
    return "000001" + _rs + "001010" + _imm;
}

string _tltiu(string rs, string imm){
    string _rs = ToBinary(CheckRegister(rs), 5);
    string _imm = ToBinary(stoi(imm), 16);
    return "000001" + _rs + "001011" + _imm;
}

string _lb(string rt, string address){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _base = ToBinary(CheckRegister(GetBase(address)), 5);
    string _offset = ToBinary(stoi(GetOffset(address)), 16);
    return "100000" + _base + _rt + _offset;
}

string _lbu(string rt, string address){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _base = ToBinary(CheckRegister(GetBase(address)), 5);
    string _offset = ToBinary(stoi(GetOffset(address)), 16);
    return "100100" + _base + _rt + _offset;
}

string _lh(string rt, string address){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _base = ToBinary(CheckRegister(GetBase(address)), 5);
    string _offset = ToBinary(stoi(GetOffset(address)), 16);
    return "100001" + _base + _rt + _offset;
}

string _lhu(string rt, string address){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _base = ToBinary(CheckRegister(GetBase(address)), 5);
    string _offset = ToBinary(stoi(GetOffset(address)), 16);
    return "100101" + _base + _rt + _offset;
}

string _lw(string rt, string address){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _base = ToBinary(CheckRegister(GetBase(address)), 5);
    string _offset = ToBinary(stoi(GetOffset(address)), 16);
    return "100011" + _base + _rt + _offset;
}

string _lwl(string rt, string address){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _base = ToBinary(CheckRegister(GetBase(address)), 5);
    string _offset = ToBinary(stoi(GetOffset(address)), 16);
    return "100010" + _base + _rt + _offset;
}

string _lwr(string rt, string address){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _base = ToBinary(CheckRegister(GetBase(address)), 5);
    string _offset = ToBinary(stoi(GetOffset(address)), 16);
    return "100110" + _base + _rt + _offset;
}

string _ll(string rt, string address){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _base = ToBinary(CheckRegister(GetBase(address)), 5);
    string _offset = ToBinary(stoi(GetOffset(address)), 16);
    return "110000" + _base + _rt + _offset;
}

string _sb(string rt, string address){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _base = ToBinary(CheckRegister(GetBase(address)), 5);
    string _offset = ToBinary(stoi(GetOffset(address)), 16);
    return "101000" + _base + _rt + _offset;
}

string _sh(string rt, string address){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _base = ToBinary(CheckRegister(GetBase(address)), 5);
    string _offset = ToBinary(stoi(GetOffset(address)), 16);
    return "101001" + _base + _rt + _offset;
}

string _sw(string rt, string address){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _base = ToBinary(CheckRegister(GetBase(address)), 5);
    string _offset = ToBinary(stoi(GetOffset(address)), 16);
    return "101011" + _base + _rt + _offset;
}

string _swl(string rt, string address){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _base = ToBinary(CheckRegister(GetBase(address)), 5);
    string _offset = ToBinary(stoi(GetOffset(address)), 16);
    return "101010" + _base + _rt + _offset;
}

string _swr(string rt, string address){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _base = ToBinary(CheckRegister(GetBase(address)), 5);
    string _offset = ToBinary(stoi(GetOffset(address)), 16);
    return "101110" + _base + _rt + _offset;
}

string _sc(string rt, string address){
    string _rt = ToBinary(CheckRegister(rt), 5);
    string _base = ToBinary(CheckRegister(GetBase(address)), 5);
    string _offset = ToBinary(stoi(GetOffset(address)), 16);
    return "111000" + _base + _rt + _offset;
}

string _mfhi(string rd){
    string _rd = ToBinary(CheckRegister(rd), 5);
    return "0000000000000000" + _rd + "00000" + "010000";
}

string _mflo(string rd){
    string _rd = ToBinary(CheckRegister(rd), 5);
    return "0000000000000000" + _rd + "00000" + "010010";
}

string _mthi(string rs){
    string _rs = ToBinary(CheckRegister(rs), 5);
    return "000000" + _rs + "000000000000000" + "010001";
}

string _mtlo(string rs){
    string _rs = ToBinary(CheckRegister(rs), 5);
    return "000000" + _rs + "000000000000000" + "010011";
}


string _syscall(){return "00000000000000000000000000001100";}

string CheckIns(string ins, vector <string> arg){
    if (ins == "add"){return _add(arg[0], arg[1], arg[2]);}
    else if (ins == "addu"){return _addu(arg[0], arg[1], arg[2]);}
    else if (ins == "addi"){return _addi(arg[0], arg[1], arg[2]);}
    else if (ins == "addiu"){return _addiu(arg[0], arg[1], arg[2]);}
    else if (ins == "and"){return _and(arg[0], arg[1], arg[2]);}
    else if (ins == "andi"){return _andi(arg[0], arg[1], arg[2]);}
    else if (ins == "clo"){return _clo(arg[0], arg[1]);}
    else if (ins == "clz"){return _clz(arg[0], arg[1]);}
    else if (ins == "div"){return _div(arg[0], arg[1]);}
    else if (ins == "divu"){return _divu(arg[0], arg[1]);}
    else if (ins == "mult"){return _mult(arg[0], arg[1]);}
    else if (ins == "multu"){return _multu(arg[0], arg[1]);}
    else if (ins == "mul"){return _mul(arg[0], arg[1], arg[2]);}
    else if (ins == "madd"){return _madd(arg[0], arg[1]);}
    else if (ins == "maddu"){return _maddu(arg[0], arg[1]);}
    else if (ins == "msub"){return _msub(arg[0], arg[1]);}
    else if (ins == "msubu"){return _msubu(arg[0], arg[1]);}
    else if (ins == "nor"){return _nor(arg[0], arg[1], arg[2]);}
    else if (ins == "or"){return _or(arg[0], arg[1], arg[2]);}
    else if (ins == "ori"){return _ori(arg[0], arg[1], arg[2]);}
    else if (ins == "sll"){return _sll(arg[0], arg[1], arg[2]);}
    else if (ins == "sllv"){return _sllv(arg[0], arg[1], arg[2]);}
    else if (ins == "sra"){return _sra(arg[0], arg[1], arg[2]);}
    else if (ins == "srav"){return _srav(arg[0], arg[1], arg[2]);}
    else if (ins == "srl"){return _srl(arg[0], arg[1], arg[2]);}
    else if (ins == "srlv"){return _srlv(arg[0], arg[1], arg[2]);}
    else if (ins == "sub"){return _sub(arg[0], arg[1], arg[2]);}
    else if (ins == "subu"){return _subu(arg[0], arg[1], arg[2]);}
    else if (ins == "xor"){return _xor(arg[0], arg[1], arg[2]);}
    else if (ins == "xori"){return _xori(arg[0], arg[1], arg[2]);}
    else if (ins == "lui"){return _lui(arg[0], arg[1]);}
    else if (ins == "slt"){return _slt(arg[0], arg[1], arg[2]);}
    else if (ins == "sltu"){return _sltu(arg[0], arg[1], arg[2]);}
    else if (ins == "slti"){return _slti(arg[0], arg[1], arg[2]);}
    else if (ins == "sltiu"){return _sltiu(arg[0], arg[1], arg[2]);}

    else if (ins == "beq"){return _beq(arg[0], arg[1], arg[2]);}
    else if (ins == "bgez"){return _bgez(arg[0], arg[1]);}
    else if (ins == "bgezal"){return _bgezal(arg[0], arg[1]);}
    else if (ins == "bgtz"){return _bgtz(arg[0], arg[1]);}
    else if (ins == "blez"){return _blez(arg[0], arg[1]);}
    else if (ins == "bltzal"){return _bltzal(arg[0], arg[1]);}
    else if (ins == "bltz"){return _bltz(arg[0], arg[1]);}
    else if (ins == "bne"){return _bne(arg[0], arg[1], arg[2]);}
    else if (ins == "j"){return _j(arg[0]);}
    else if (ins == "jal"){return _jal(arg[0]);}

    else if (ins == "jalr"){return _jalr(arg[0], arg[1]);}
    else if (ins == "jr"){return _jr(arg[0]);}
    else if (ins == "teq"){return _teq(arg[0], arg[1]);}
    else if (ins == "teqi"){return _teqi(arg[0], arg[1]);}
    else if (ins == "tne"){return _tne(arg[0], arg[1]);}
    else if (ins == "tnei"){return _tnei(arg[0], arg[1]);}
    else if (ins == "tge"){return _tge(arg[0], arg[1]);}
    else if (ins == "tgeu"){return _tgeu(arg[0], arg[1]);}
    else if (ins == "tgei"){return _tgei(arg[0], arg[1]);}
    else if (ins == "tgeiu"){return _tgeiu(arg[0], arg[1]);}
    else if (ins == "tlt"){return _tlt(arg[0], arg[1]);}
    else if (ins == "tltu"){return _tltu(arg[0], arg[1]);}
    else if (ins == "tlti"){return _tlti(arg[0], arg[1]);}
    else if (ins == "tltiu"){return _tltiu(arg[0], arg[1]);}
    else if (ins == "lb"){return _lb(arg[0], arg[1]);}
    else if (ins == "lbu"){return _lbu(arg[0], arg[1]);}
    else if (ins == "lh"){return _lh(arg[0], arg[1]);}
    else if (ins == "lhu"){return _lhu(arg[0], arg[1]);}
    else if (ins == "lw"){return _lw(arg[0], arg[1]);}
    else if (ins == "lwl"){return _lwl(arg[0], arg[1]);}
    else if (ins == "lwr"){return _lwr(arg[0], arg[1]);}
    else if (ins == "ll"){return _ll(arg[0], arg[1]);}
    else if (ins == "sb"){return _sb(arg[0], arg[1]);}
    else if (ins == "sh"){return _sh(arg[0], arg[1]);}
    else if (ins == "sw"){return _sw(arg[0], arg[1]);}
    else if (ins == "swl"){return _swl(arg[0], arg[1]);}
    else if (ins == "swr"){return _swr(arg[0], arg[1]);}
    else if (ins == "sc"){return _sc(arg[0], arg[1]);}
    else if (ins == "mfhi"){return _mfhi(arg[0]);}
    else if (ins == "mflo"){return _mflo(arg[0]);}
    else if (ins == "mthi"){return _mthi(arg[0]);}
    else if (ins == "mtlo"){return _mtlo(arg[0]);}
    else if (ins == "syscall"){return _syscall();}
    else {return "NO INSTRUCTION";}
}

string KeyInfo(string s){
    string beg;
    int index = 0;
    if(!s.empty()){
        s.erase(0, s.find_first_not_of("\t"));
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
    }
    beg = s[0];
    if (s == ".text"){return "#";}
    else if (s == ".data"){return "#";}
    if (beg == "#"){
        return "#";
    }else if(s.find("#") != string::npos){
        index = s.find("#");
        s = s.substr(0, index);
    }
    return s;
}

string GetIns(string line){
    if (line == "syscall"){return line;}
    int last = line.find_first_of(" ");
    if (last == -1){
        last = 1;
    }
    string tem = line.substr(0, last);
    return tem;
}

void  GetArgs(string line, vector <string> &tem){
    int index = 0;
    for (int i = 0; i < 3;  i++){
        if (line.find_first_of(",") != string::npos){
            index = line.find(",");
            tem.push_back(line.substr(0, index));
            line.erase(0,  index + 2);
        }else{
            tem.push_back(line);
            break;
        }
    }
}

string GetTarget(vector <string> &all, string &target, string &ins, int row){
    int len = all.size(), ins_address, label_address, tem = 0;
    string label = target + ":", tar = " " + target;

    for (int i = 0; i < len; i++){
        if (all[i].find(label) != string::npos){
            label_address = tem;
            break;
        }else if (all[i].find(":") != string ::npos){
            continue;
        }
        else if (all[i] == "#"){
            continue;
        }
        tem += 1;
    }
    tem = 0;
    for (int i = 0; i <= row; i++){
        if (all[i].find(":") != string ::npos){
            continue;
        }
        else if (all[i] == "#"){
            continue;
        }

        tem += 1;
    }
    ins_address = tem;

    string tep;
    if (ins == "j"){tep = to_string(label_address + 0x100000);}
    else if (ins == "jal"){tep = to_string(label_address + 0x100000);}

    else if (ins == "beq"){tep = to_string(label_address - ins_address);}
    else if (ins == "bgez"){tep = to_string(label_address - ins_address);}
    else if (ins == "bgezal"){tep = to_string(label_address - ins_address);}
    else if (ins == "bgtz"){tep = to_string(label_address - ins_address);}
    else if (ins == "blez"){tep = to_string(label_address - ins_address);}
    else if (ins == "bltzal"){tep = to_string(label_address - ins_address);}
    else if (ins == "bltz"){tep = to_string(label_address - ins_address);}
    else if (ins == "bne"){tep = to_string(label_address - ins_address);}
    else {tep = target;}
    return tep;
}

void test(){
    string line, ins, args, result, tem;
    vector <string> ALL;
    int count = 0;
    while (count <= 5 && cin.good()){
        getline(cin, line);
        if (line.empty()){
            count += 1;
            continue;
        }
        else {count = 0;}
        if (count == 3){break;}
        line = KeyInfo(line);
        ALL.push_back(line);
    }
    int len = ALL.size();
    for (int i = 0; i < len; i++){
        vector <string> arg;
        line = KeyInfo(ALL[i]);
        if (line == "#"){continue;}
        if (line.find(":") != string::npos){continue;}
        ins = GetIns(line);
        args = line.substr(ins.length(), line.length());
        args = KeyInfo(args);
        GetArgs(args, arg);
        if (ins == "j"){tem = arg[0]; arg[0] = GetTarget(ALL, tem, ins, i);}
        else if (ins == "jal"){tem = arg[0]; arg[0] = GetTarget(ALL, tem, ins, i);}
        GetArgs(args, arg);
        if (ins == "beq"){tem = arg[2]; arg[2] = GetTarget(ALL, tem, ins, i);}
        else if (ins == "bgez"){tem = arg[1]; arg[1] = GetTarget(ALL, tem, ins, i);}
        else if (ins == "bgezal"){tem = arg[1]; arg[1] = GetTarget(ALL, tem, ins, i);}
        else if (ins == "bgtz"){tem = arg[1]; arg[1] = GetTarget(ALL, tem, ins, i);}
        else if (ins == "blez"){tem = arg[1]; arg[1] = GetTarget(ALL, tem, ins, i);}
        else if (ins == "bltzal"){tem = arg[1]; arg[1] = GetTarget(ALL, tem, ins, i);}
        else if (ins == "bltz"){tem = arg[1]; arg[1] = GetTarget(ALL, tem, ins, i);}
        else if (ins == "bne"){tem = arg[2]; arg[2] = GetTarget(ALL, tem, ins, i);}
        result = CheckIns(ins, arg);
        cout << result << endl;
    }

}

int main()
{
    test();

    return 0;
}
