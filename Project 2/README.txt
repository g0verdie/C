Archiving data structures

README: this file

FEV.h
FEVtypes.h:  define particular struct types for silly-simple
              graphical representation: faces, edges, vertices.
              a face is in a circ. list of faces, each of which has
              a circ. list of edges, each of which has two vertices,
              each of which has a matrix.

FEV.c:  a ton of hastily-written maybe-useful utilities for creating,
	printing, reading... FEV structs.  Lots of annoying debugging
	output: should have " if (DEBUG)" in front of all printfs.
  
tetra.c:   produces a pointer to a legal tetrahedron 
           linked (non-printable) data structure.

struct_to_file.c:  
             prints out the structure in my own format. I also have not
             used the methods written by Chris Brown, neither have I used the
             indeces or arrays. I mostly used recursive methods that take care
             of printing things out in addition to the do while loops. The hardest
             part writing this coming up with a solution to stop the infinite loops
             caused by the excessive recursion. The format to output a structure to
             the file is face_to_file(NAME OF FILEREADER, HEAD FACE NAME)

struct_to_file_format:  My own file format. It lists fev types, ID and, in case of 
                        vertices, x y z coordinates. More detailed explanation is listed
                        in the actual file

file_to_struct.c:  I haven't used CB's code at all for this, neither have I used arrays,
                    indeces, and my code only needs to read the file once to put everything
                    in a structure and link everything to each other on the go.
                    The main ideas is very similar to struct to file where I have a bunch of 
                    recursive functions combined with the while and do while loops to pick up
                    the values and link everything together. The hardest part was trying to make
                    the face loop stop at the end of the file which I solved by checking how much
                    data fscanf is receiving. The format to take in the file and recreate an entire
                    structure is face_t face_name = file_make_structs(NAME OF FILEREADER). This will do everything
                    for you structure building wise.

matrix code:  all we need (creation and printing) is in the ../matrix directory.

psfile_in.data:  very simple nonsense FEV structure file for debugging. 

psfile_out.data: the file I get by running file_to_struct 
		 on psfile_in.dat and running
		 struct_to_file on the result (a get_put_get) scenario,
		 complentary to the put-get_put scenario of the assignment).

put_get_put.c:  creates, archives, reconstructs, rearchives a tetrahedron.

Maketest: produces the executable for demonstrations like the above.

mini_example/:  was meant to help, but may just be waste of your
		time.   Feel free to ignore.
