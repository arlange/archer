#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

#include "command.h"
#include "g.h"
#include "graph_commands.h"

using namespace std;

get_edges_command::get_edges_command(){
  name = "num_e";
  GraphCommandBase::base().register_c( name, this );
}

void get_edges_command::execute( g * graph, vector<string> args){
  vector<string>::iterator pos = args.begin() + 2;
  if( pos != args.end() ){
    throw "Invalid argument number for " + name;
  }

  cout << graph->num_edges( ) << endl;
}


order_command::order_command(){
  name = "order";
  GraphCommandBase::base().register_c( name, this );
}

void order_command::execute( g * graph, vector<string> args){
  vector<string>::iterator pos = args.begin() + 2;
  if( pos != args.end() ){
    throw "Invalid argument number for " + name;
  }

  cout << graph->order() << endl;
}


remove_edge_command::remove_edge_command(){
  name = "remove_e";
  GraphCommandBase::base().register_c( name, this );
}

void remove_edge_command::execute( g * graph, vector<string> args){
  vector<string>::iterator pos = args.begin() + 2;
  vector<int> iArgs;
  for( int i = 0; i < 2; i++ ){
    if( pos == args.end() ){
      throw "Invalid argument number for " + name;
    } 
    iArgs.push_back( atoi( pos->c_str() ));
    pos++;
  }

  graph->remove_edge( iArgs[0], iArgs[1] );
}


add_edge_command::add_edge_command(){
  name = "add_e";
  GraphCommandBase::base().register_c( name, this );
}

void add_edge_command::execute( g * graph, vector<string> args){
  vector<string>::iterator pos = args.begin() + 2;
  vector<int> iArgs;
  for( int i = 0; i < 2; i++ ){
    if( pos == args.end() ){
      throw "Invalid argument number for " + name;
    } 
    iArgs.push_back( atoi( pos->c_str() ));
    pos++;
  }

  graph->add_edge( iArgs[0], iArgs[1] );
}


add_circ_edge_command::add_circ_edge_command(){
  name = "add_ce";
  GraphCommandBase::base().register_c( name, this );
}

void add_circ_edge_command::execute( g * graph, vector<string> args){
  vector<string>::iterator pos = args.begin() + 2;
  if( pos + 1 != args.end() ){
    throw "Invalid argument number for " + name;
  }
  graph->add_circ_edge( atoi( pos->c_str() ) );
}


remove_circ_edge_command::remove_circ_edge_command(){
  name = "remove_ce";
  GraphCommandBase::base().register_c( name, this );
}

void remove_circ_edge_command::execute( g * graph, vector<string> args){
  vector<string>::iterator pos = args.begin() + 2;
  if( pos + 1 != args.end() ){
    throw "Invalid argument number for " + name;
  }
  graph->remove_circ_edge( atoi( pos->c_str() ) );
}


remove_dist_vs_command::remove_dist_vs_command(){
  name = "remove_vsd";
  GraphCommandBase::base().register_c( name, this );
}

void remove_dist_vs_command::execute( g * graph, vector<string> args){
  vector<string>::iterator pos = args.begin() + 2;
  if( pos + 2 != args.end() ){
    throw "Invalid argument number for " + name;
  }
  graph->remove_distvs( atoi( pos->c_str() ), atoi( (pos+1)->c_str()) );
}


remove_rand_vs_command::remove_rand_vs_command(){
  name = "remove_vs_rand";
  GraphCommandBase::base().register_c( name, this );
}

void remove_rand_vs_command::execute( g * graph, vector<string> args){
  vector<string>::iterator pos = args.begin() + 2;
  if( pos + 1 != args.end() ){
    throw "Invalid argument number for " + name;
  }
  graph->remove_randvs( atoi( pos->c_str() ) );
}


make_cyc_command::make_cyc_command(){
  name = "mk_cyc";
  GraphCommandBase::base().register_c( name, this );
}

void make_cyc_command::execute( g * graph, vector<string> args){
  vector<string>::iterator pos = args.begin() + 2;
  if( pos != args.end() ){
    throw "Invalid argument number for " + name;
  }
  graph->make_cycle();
}


make_comp_command::make_comp_command(){
  name = "mk_k";
  GraphCommandBase::base().register_c( name, this );
}

void make_comp_command::execute( g * graph, vector<string> args){
  vector<string>::iterator pos = args.begin() + 2;
  if( pos != args.end() ){
    throw "Invalid argument number for " + name;
  }
  graph->make_complete();
}


make_res_circ_command::make_res_circ_command(){
  name = "mk_rc";
  GraphCommandBase::base().register_c( name, this );
}

void make_res_circ_command::execute( g * graph, vector<string> args){
  vector<string>::iterator pos = args.begin() + 2;
  if( pos + 1 != args.end() ){
    throw "Invalid argument number for " + name;
  }
  graph->make_residue_circ( atoi( pos->c_str() ) );
}


make_l_circ_command::make_l_circ_command(){
  name = "mk_lc";
  GraphCommandBase::base().register_c( name, this );
}

void make_l_circ_command::execute( g * graph, vector<string> args){
  vector<string>::iterator pos = args.begin() + 2;
  if( pos + 1 != args.end() ){
    throw "Invalid argument number for " + name;
  }
  graph->make_l_circ( atoi( pos->c_str() ) );
}


make_joined_command::make_joined_command(){
  name = "mk_join";
  GraphCommandBase::base().register_c( name, this );
}

void make_joined_command::execute( g * graph, vector<string> args ){
}

void make_joined_command::execute( g * graph, vector<g*> args){
  graph->join_graphs( args.size(), args );
}


make_connected_command::make_connected_command(){
  name = "mk_conn";
  GraphCommandBase::base().register_c( name, this );
}

void make_connected_command::execute( g * graph, vector<string> args ){
}

void make_connected_command::execute( g * graph, vector<g*> args){
  graph->connect_graphs( args[1], args[0] );
}



make_avoid_connected_command::make_avoid_connected_command(){
  name = "mk_aconn";
  GraphCommandBase::base().register_c( name, this );
}

void make_avoid_connected_command::execute( g * graph, vector<string> args ){
}

void make_avoid_connected_command::execute( g * graph, vector<g*> args){
  cout << graph->connect_graphs( args[1], args[0], true, 4 ) << " edges added." << endl;
}



make_galois_circ_command::make_galois_circ_command(){
  name = "mk_gc";
  GraphCommandBase::base().register_c( name, this );
}

void make_galois_circ_command::execute( g * graph, vector<string> args){
  vector<string>::iterator pos = args.begin() + 2;
  if( pos + 3 != args.end() ){
    throw "Invalid argument number for " + name;
  }
  graph->make_galois_circ( atoi(pos->c_str()),atoi((pos+1)->c_str()),
			   atoi((pos+2)->c_str()));
}


make_circ_command::make_circ_command(){
  name = "mk_circ";
  GraphCommandBase::base().register_c( name, this );
}

void make_circ_command::execute( g * graph, vector<string> args){
  vector<string>::iterator pos = args.begin() + 2;
  if( pos + 1 != args.end() ){
    throw "Invalid argument number for " + name;
  }

  string filename = *pos;
  ifstream dists( filename.c_str() );
  int k;
  int d;
  vector< int > ds;
  if( dists.is_open() ){
    dists >> k;
    for( int i = 0; i < k; i++ ){
      dists >> d;
      ds.push_back( d );
    }
  }
  else{
    throw "Error opening file " + filename;
  }
  graph->make_circ( ds );
}


make_embedded_rc_command::make_embedded_rc_command(){
  name = "mk_erc";
  GraphCommandBase::base().register_c( name, this );
}

void make_embedded_rc_command::execute( g * graph, vector<string> args){
  vector<string>::iterator pos = args.begin() + 2;
  if( pos + 2 != args.end() ){
    throw "Invalid argument number for " + name;
  }
  
  graph->make_embedded_rc( atoi( pos->c_str() ), atoi( (pos+1)->c_str()) );
}



load_adj_command::load_adj_command(){
  name = "ld_adj";
  GraphCommandBase::base().register_c( name, this );
}

void load_adj_command::execute( g * graph, vector<string> args){
  vector<string>::iterator pos = args.begin() + 2;
  if( pos + 1 != args.end() ){
    throw "Invalid argument number for " + name;
  }
  
  graph->load_adj( *pos );
}



add_all_noncrit_command::add_all_noncrit_command(){
  name = "add_all";
  GraphCommandBase::base().register_c( name, this );
}

void add_all_noncrit_command::execute( g * graph, vector<string> args){
  vector<string>::iterator pos = args.begin() + 2;
  if( pos+1 != args.end() ){
    throw "Invalid argument number for " + name;
  }
  int k = atoi( pos->c_str() );
  int added = graph->add_all_noncrit(true,k);
  cout << "Added " << added << " edges avoiding K" << k << endl;
}



add_all_ce_command::add_all_ce_command(){
  name = "add_allce";
  GraphCommandBase::base().register_c( name, this );
}

void add_all_ce_command::execute( g * graph, vector<string> args){
  vector<string>::iterator pos = args.begin() + 2;
  int k = 4;
  if( pos != args.end() ){
    throw "Invalid argument number for " + name;
  }
  vector<int> added = graph->add_all_ce();
  //cout << "Added distances " << added << endl;
}


add_all_cer_command::add_all_cer_command(){
  name = "add_allcer";
  GraphCommandBase::base().register_c( name, this );
}

void add_all_cer_command::execute( g * graph, vector<string> args){
  vector<string>::iterator pos = args.begin() + 2;
 
  if( pos+1 != args.end() && pos+3 != args.end() ){
    throw "Invalid argument number for " + name;
  }

  int k = atoi( pos->c_str() );
  pos++;
  
  vector<int> added = graph->add_all_ce_rand(true,k);
  
  if( pos != args.end() ){
    string filename = *pos;
    string gname = *(pos+1);
    fstream distLog;
    distLog.open(filename.c_str(), fstream::in | fstream::out | fstream::app );
    distLog << gname;
    distLog << " - added distances: ";
    for( vector<int>::iterator it = added.begin(); it != added.end(); it++ ){
      distLog << *it << " ";
    }
    distLog << endl;
  }
  for( vector<int>::iterator it = added.begin(); it != added.end(); it++ ){
    cout << *it << " ";
  }
  cout << endl;
}


remove_k_command::remove_k_command(){
  name = "remove_k";
  GraphCommandBase::base().register_c( name, this );
}

void remove_k_command::execute( g * graph, vector<string> args){
  vector<string>::iterator pos = args.begin() + 2;
  if( pos + 1 != args.end() ){
    throw "Invalid argument number for " + name;
  }
  int k = atoi( pos->c_str() );
  int removed = graph->remove_k( k );
  cout << "Removed " << removed << " edges" << endl;
}


count_k_command::count_k_command(){
  name = "count_k";
  GraphCommandBase::base().register_c( name, this );
}

void count_k_command::execute( g * graph, vector<string> args){
  vector<string>::iterator pos = args.begin() + 2;
  if( pos + 1 != args.end() ){
    throw "Invalid argument number for " + name;
  }
  int k = atoi( pos->c_str() );
  int count = graph->remove_k( k, false );
  cout << "Graph has " << count << " K" << k << "'s" << endl;
}



print_command::print_command(){
  name = "print";
  GraphCommandBase::base().register_c( name, this );
}

void print_command::execute( g * graph, vector<string> args){
  vector<string>::iterator pos = args.begin() + 2;
  if( pos != args.end() ){
    throw "Invalid argument number for " + name;
  }
  graph->print();
}


print_sparse_command::print_sparse_command(){
  name = "printf_sh";
  GraphCommandBase::base().register_c( name, this );
}

void print_sparse_command::execute( g * graph, vector<string> args){
  vector<string>::iterator pos = args.begin() + 2;
  if( pos + 1 != args.end() ){
    throw "Invalid argument number for " + name;
  }
  string filename = *pos;
  ofstream sparseH (filename.c_str());
  if( sparseH.is_open() ){
    graph->print_sparse_h( &sparseH );
  }
  else{
    throw "Error opening file " + filename;
  }
}


print_sdpa_command::print_sdpa_command(){
  name = "printf_sdp";
  GraphCommandBase::base().register_c( name, this );
}

void print_sdpa_command::execute( g * graph, vector<string> args){
  vector<string>::iterator pos = args.begin() + 2;
  if( pos + 1 != args.end() ){
    throw "Invalid argument number for " + name;
  }
  string filename = *pos;
  ofstream sparseH (filename.c_str());
  if( sparseH.is_open() ){
    graph->print_sdpa( &sparseH );
  }
  else{
    throw "Error opening file " + filename;
  }
}


print_rudy_command::print_rudy_command(){
  name = "printf_rh";
  GraphCommandBase::base().register_c( name, this );
}

void print_rudy_command::execute( g * graph, vector<string> args){
  vector<string>::iterator pos = args.begin() + 2;
  if( pos + 1 != args.end() ){
    throw "Invalid argument number for " + name;
  }
  string filename = *pos;
  ofstream sparseH (filename.c_str());
  if( sparseH.is_open() ){
    graph->print_sparse_h( &sparseH, true );
  }
  else{
    throw "Error opening file " + filename;
  }
}


print_sat_command::print_sat_command(){
  name = "printf_sat";
  GraphCommandBase::base().register_c( name, this );
}

void print_sat_command::execute( g * graph, vector<string> args){
  vector<string>::iterator pos = args.begin() + 2;
  if( pos + 1 != args.end() ){
    throw "Invalid argument number for " + name;
  }
  string filename = *pos;
  ofstream sparseH (filename.c_str());
  if( sparseH.is_open() ){
    graph->print_sat( &sparseH );
  }
  else{
    throw "Error opening file " + filename;
  }
}


print_sat34_command::print_sat34_command(){
  name = "printf_sat34";
  GraphCommandBase::base().register_c( name, this );
}

void print_sat34_command::execute( g * graph, vector<string> args){
  vector<string>::iterator pos = args.begin() + 2;
  if( pos + 1 != args.end() ){
    throw "Invalid argument number for " + name;
  }
  string filename = *pos;
  ofstream sparseH (filename.c_str());
  if( sparseH.is_open() ){
    graph->print_sat34( &sparseH );
  }
  else{
    throw "Error opening file " + filename;
  }
}


print_satv44_command::print_satv44_command(){
  name = "printf_satv44";
  GraphCommandBase::base().register_c( name, this );
}

void print_satv44_command::execute( g * graph, vector<string> args){
  vector<string>::iterator pos = args.begin() + 2;
  if( pos + 1 != args.end() ){
    throw "Invalid argument number for " + name;
  }
  string filename = *pos;
  ofstream sparseH (filename.c_str());
  if( sparseH.is_open() ){
    graph->print_satv44( &sparseH );
  }
  else{
    throw "Error opening file " + filename;
  }
}

get_edges_command getEdgesCommand;
order_command getOrderCommand;
remove_edge_command removeEdgeCommand;
add_edge_command addEdgeCommand;
add_circ_edge_command addCircEdgeCommand;
remove_circ_edge_command removeCircEdgeCommand;
remove_dist_vs_command removeDistVsCommand;
remove_rand_vs_command removeRandVsCommand;
make_cyc_command makeCycCommand;
make_comp_command makeCompCommand;
make_res_circ_command makeResCircCommand;
make_l_circ_command makeLCircCommand;
make_galois_circ_command makeGaloisCircCommand;
make_circ_command makeCircCommand;
make_embedded_rc_command makeEmbeddedRCCommand;
load_adj_command loadAdjCommand;
make_joined_command makeJoinedCommand;
make_connected_command makeConnectedCommand;
make_avoid_connected_command makeAvoidConnectedCommand;
add_all_noncrit_command addAllNonCritCommand;
add_all_ce_command addAllCECommand;
add_all_cer_command addAllCERCommand;
remove_k_command removeKCommand;
count_k_command countKCommand;
print_sparse_command printSparseCommand;
print_sdpa_command printSDPACommand;
print_command printCommand;
print_rudy_command printRudyCommand;
print_sat_command printSatCommand;
print_sat34_command printSat34Command;
print_satv44_command printSatV44Command;
