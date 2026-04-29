// Room: /d/tangmen/guodao.c         
//writen by tang

inherit ROOM;

void create()
{
        	set("short", "过道");
        	set("long", @LONG
连接前后院的过道，一个高大威猛的老者站在这，如果想加入唐门，跟他
说就可以了。
LONG
        		);
        	set("exits", ([ /* sizeof() == 2 */
  		"north"  : __DIR__"keting",
  		"south"  : __DIR__"qianyuan",  
		"west"   : __DIR__"wzoulang1",
		"east"    : __DIR__"ezoulang1",
		]));                      
	set("objects", ([
		CLASS_D("tangmen")+"/tangbing"  :1
			]));
        	setup();

}            

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "唐门") && dir == "west" &&
		objectp(present("tang bing", environment(me))))
	   return notify_fail("唐冰喝道：你不是唐门弟子，不得入内。\n");
		
        return ::valid_leave(me, dir);
}
           