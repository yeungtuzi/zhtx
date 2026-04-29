// Room: /city/shuyuan.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "书院");
	set("long", @LONG
这里是村里的书院，窗明几净，一尘不染。一位庄重严肃的老者坐在太师
椅上讲学，那是本村的老秀才。在他的两侧坐了求学的学生。一张书案放在老
秀才的前面，案上摆着几本翻开了的线装书籍。嵌在讲堂前左壁上有这里的学
规(xuegui)。
LONG
	);

	set("exits", ([
                "east" : __DIR__"sroad2",
	]));

	set("item_desc", ([
		"xuegui" : "日讲经书三起，日看纲目数页。"  
			"\n通晓时务物理，参读古文诗赋。" 
			"\n读书必须过笔，会课按时蚤完。"
			"\n夜读仍戒晏起，疑误定要力争。\n\n"
                        "求学需缴学费五两\n",
	]));
	
	set("objects", ([
		__DIR__"npc/xiucai" : 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	me->set_temp("mark/朱", 0);
	return 1;
}

