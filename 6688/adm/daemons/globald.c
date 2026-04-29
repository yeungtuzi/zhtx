inherit F_DBASE;
mapping nolog_cmd = ([
        "ann":1 , 
	"call":1, "cd":1,"chat":1 , "chat*":1 , "ct":1,"ce":1,
	"emote":1,"es":1, "es*":1,
        "finger":1, 
	"gtell":1,"go":1, "gwiz":1,
        "hp":1, 
	"inventory":1, 
	"ls":1,"look":1 ,
	"mp":1,"music":1, 
	"new":1, "new*":1,
        "reply":1, "rumor":1, 
	"say":1, "score":1, "shout":1, "skills":1,
        "sys":1, 
	"tell":1, "tt":1, "twiz":1, 
	"update":1,
	"whisper":1, "who":1, "wiz":1, "wiz*":1,

// emote 
	"?":1,"faint":1,
	"hi":1,"hehe":1,"hug":1,"kick":1,"kiss1":1, "kok":1, 
	"nod":1,"sigh":1,
	"pat":1,
	"xixi":1,
        ]);

int is_nolog_cmd(string cmd) {

	return nolog_cmd[cmd];
}


//Calculate 21 numbers, 菲波那契数列
int *fbnq = ({ 
1,
1,
2,
3,
5,
8,
13,
21,
34,
55,
89,
144,
233,
377,
610,
987,
1597,
2584,
4181,
6765,
10946,
17711,
28657,
46368,
75025,
121393,
196418,
317811,
514229,
832040,
1346269,
2178309 });

//total sum is: 5702884
int query_fbnq(int index)
{
	if( index >= sizeof(fbnq) || index < 0)
		return 0;
	return fbnq[index];
}

int *query_fbnq_array()
{
	return fbnq;
}

