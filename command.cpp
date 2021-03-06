#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <stdlib.h>

#include "command.h"

void GraphCommand::execute( g * graph, vector<g*> args){
}

string GraphCommand::get_name(){
  return name;
}

string GraphCommand::get_desc(){
  return description;
}

GraphCommandBase & GraphCommandBase::base(){
  static GraphCommandBase gcb;
  return gcb;
}

void GraphCommandBase::split( string &line, char delim, vector<string> &parts ){
  stringstream ss( line );
  string item;
  while( getline( ss, item, delim) ){
    if( !item.empty() ){
      parts.push_back( item );
    }
  }
}

GraphCommand * GraphCommandBase::lookup_command( const string & c ){
  c_map::iterator it = cmdMap.find(c);
  if( it == cmdMap.end() ){
    throw "Error: Invalid Command " + c;
  }
  return it->second;
}

g * GraphCommandBase::lookup_graph( const string & c, const string & gs ){
  g_map::iterator it = graphMap.find(gs);
  if( it == graphMap.end() ){
      throw "Error: Graph does not exist";
  }
  return it->second;
}


void GraphCommandBase::run(){
  string command;
  cout << prompt;
  getline( cin, command );
  while( command != "exit" && command != "quit" ){
    if( !command.empty()){  
      vector<string> parts;
      split( command, ' ', parts );
      try{
	if( parts[0] == "create" ){
	  if( parts.size() != 3 ){
	    throw "Error: invalid number of arguments for create";
	  }
	  else{
	    register_g( parts[1], new g( atoi( parts[2].c_str() ) ) );
	  }
	}
	else if( parts[0] == "mk_join" || parts[0] == "mk_conn" || 
		 parts[0] == "mk_aconn" || parts[0] == "mk_arconn" ){
	  vector<g*> graphs;
	  while( parts.size() > 2 ){
	    graphs.push_back( lookup_graph( parts[0], parts.back() ) );
	    parts.pop_back();
	  }
	  lookup_command(parts[0])->execute( lookup_graph(parts[0], parts[1]),
					     graphs );
	}
	else if( parts[0] == "help" ){
	  cout << "*************************************************" << endl;
	  cout << "  COMMAND \t\t DESCRIPTION" << endl;
	  for( map< string, GraphCommand* >::iterator it = cmdMap.begin();
	       it != cmdMap.end(); it++ ){
	    string space;
	    string c_name = it->second->get_name();
	    if( c_name.length() < 8 ){
	      space = "\t\t";
	    }
	    else{
	      space = "\t";
	    }
	    cout << c_name << space << it->second->get_desc() << endl;
	  }
	  cout << "*************************************************" << endl;

	}
	else{
	  lookup_command(parts[0])->execute( lookup_graph(parts[0], parts[1]), 
					     parts );
	}
      }
      catch( const string error ){
	cerr << error << endl;
      }
      catch( const char * err ){
	cerr << err << endl;
      }
    }
    cout << prompt;
    getline( cin, command );
  }
}

void GraphCommandBase::register_g( const string name, g * graph ){
  graphMap.insert( pair<string,g*>( name, graph ) );
}

void GraphCommandBase::register_c( const string name, GraphCommand * cmd ){
  cmdMap.insert( pair<string,GraphCommand*>(name, cmd ) );
}
