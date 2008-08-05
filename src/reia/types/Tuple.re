#
# Tuple: Methods for the Tuple pseudo-class
# Copyright (C)2008 Tony Arcieri
# 
# Redistribution is permitted under the MIT license.  See LICENSE for details.
#

module Tuple
  # Tuple#to_list
  #   Convert a tuple to a list
  def funcall(tuple, ~to_list, [])
    erlang::tuple_to_list(tuple)
  
  # Tuple#[]
  #   Retrieve an element from a Tuple
  def funcall(tuple, ~'[]', [index])
    erlang::element(index + 1, tuple)
  
  # Tuple#to_s
  #   Generate a string representation of a Tuple  
  def funcall(tuple, ~to_s, [])
    ["(", tuple.to_list().map { |e| e.to_s() }.join(","), ")"].join()
    
  # Tuple#size
  #   Return the number of elements in a Tuple
  def funcall(tuple, ~size, [])
    erlang::tuple_size(tuple)