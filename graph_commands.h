//
// File: graph_command.h
//

#include "command.h"
#include "g.h"

class remove_edge_command : public GraphCommand{
 public:
  remove_edge_command();

 public:
  void execute( g * graph, vector<string> args);
};


class add_edge_command : public GraphCommand{
 public:
  add_edge_command();

 public:
  void execute( g * graph, vector<string> args);
};


class print_command : public GraphCommand{
 public:
  print_command();

 public:
  void execute( g * graph, vector<string> args);
};


class make_res_circ_command : public GraphCommand{
 public:
  make_res_circ_command();

 public:
  void execute( g * graph, vector<string> args);
};


class make_circ_command : public GraphCommand{
 public:
  make_circ_command();

 public:
  void execute( g * graph, vector<string> args);
};


class add_all_noncrit_command : public GraphCommand{
 public:
  add_all_noncrit_command();

 public:
  void execute( g * graph, vector<string> args);
};


class remove_k_command : public GraphCommand{
 public:
  remove_k_command();

 public:
  void execute( g * graph, vector<string> args);
};


class print_sparse_command : public GraphCommand{
 public:
  print_sparse_command();

 public:
  void execute( g * graph, vector<string> args);
};
