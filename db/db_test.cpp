#include <iostream>
#include <stdio.h>
#include <stdexcept>

#define OTL_ODBC
#define OTL_ODBC_UNIX
#include "otlv4.h"

using std::string;
using std::runtime_error;



string get_env_var(string var){
	if(const char* env_p = std::getenv(var.c_str())){
		return string(env_p);
	}else{
		throw runtime_error("Environment variable " + var + " is required\n");
	}	
}


int main(){
	string driver = "{MySQL}";
	string server_ip = "test-db.cmuwbw5qde2i.us-west-2.rds.amazonaws.com";
	string port = "3306";
	string user = get_env_var("DB_USR");
	string pass = get_env_var("DB_PWD");
	string database = "test_db";

	string conn_str = "DRIVER=" +  driver + ";SERVER=" + server_ip + ";PORT=" + port  + ";USER=" + user + ";PASSWORD=" + pass + ";DATABASE=" + database;

	otl_connect db;
	otl_connect::otl_initialize();	


	try{
		db.rlogon(conn_str.c_str());
		otl_cursor::direct_exec(db, "drop table temp", otl_exception::disabled);
		otl_cursor::direct_exec(db, "create table temp(f1 int, f2 varchar(30))");

		
		db.logoff(); 

	}catch(otl_exception& p){
		std::cerr << p.msg<< std::endl; 
  		std::cerr << p.stm_text<< std::endl; 
 		std::cerr << p.var_info<< std::endl; 
	}
}