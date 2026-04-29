// Room: /u/cuer/emei/shanmen.c
//cuer

inherit ROOM;

void create()
{
	set("short", "山门");
	set("long", @LONG
这里是峨嵋山的山门，迎面一座高大的汉白玉山门。
石阶从山门下穿过，山门的后面是一座雄伟的大殿，那
就是峨嵋的山门殿。山门旁有一群峨嵋派的守山弟子在
检查过往行人，不是峨嵋派的不让上山。还有一个慈祥
的中年尼姑在接待想加入峨嵋派的朋友。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shmdian",
  "westdown" : __DIR__"yunvchi",
]));
	set("no_clean_up", 0);
        set("objects",([
               __DIR__"npc/wenxu" : 1, 
               __DIR__"npc/shoushan" : 4,  
            ]));         
	setup();
}


int valid_leave(object me, string dir)
{
        if (!wizardp(me) && objectp(present("shoushan dizi", environment(me)))
		&& dir == "north" )  {
		if(me->query_temp("invited_by_emei")) {
			write("守山弟子说: 这位施主请！\n");	  	
		}
		else if(  (string)me->query("family/family_name") != "峨嵋派")
                	return notify_fail("守山弟子说: 非我派弟子不许上峨嵋山。\n");
	}
        return ::valid_leave(me, dir);
}
