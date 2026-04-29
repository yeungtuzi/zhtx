// yunv.c 玉女峰

inherit ROOM;
void del_exits();
void create()
{
        set("short", "玉女峰");
	set("long", 
@LONG
这里就是华山的中峰--玉女峰。传说秦穆公的女儿和女婿--弄玉和箫史就
是在这里升仙的。从此，人们把中峰叫“玉女峰”。后来，人们又在玉女峰上
修建了“引凤亭”。如今，玉女峰上仍有玉女的遗迹，如：玉女洗头盆，盆中
清水溶溶，冬不结冰，夏不污腐。此外，还有玉女梳妆台、玉女洞、箫史洞，
此石洞西边有一窟，名龙窟。据说，每当箫史吹起箫来，神龙便卧在这里。玉
女峰虽不如天外三峰之高险，景致却极优雅，历代留下的摩崖题刻很多。如“
双手擎天”、“揪剑吉祥”、“砥柱中天”等笔力雄劲，龙飞凤舞。
 
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
		  "eastdown" : __DIR__"zhandao2",
	]));


        set("outdoors", "huashan" );

        setup();
}

void init()
{
	
	if(this_player()->query("mark/secret/6_ask_fox")
	|| this_player()->query("mark/secret_success"))
	{
		set("exits/enter",__DIR__"hole");
		set("open_player",this_player()->query("id"));
	}
	::reset();
}

int valid_leave(object me,string dir)
{
	if(userp(me) && dir=="up")
	{
		if(query("open_player")==this_player()->query("id"))
		{
			remove_call_out("del_exits");
			call_out("del_exits",1);
	
			return 1;
		}
		return notify_fail("你看了看那黝黑的山洞，算了吧，还是不要进去了。\n");
	}			
	if(query("exits/enter"))
	{
		remove_call_out("del_exits");
		call_out("del_exits",1);
	}
	return 1;
}

void del_exits()
{
	delete("exits/enter");
	delete("open_player");
}
