//beike.c
//by emote

inherit ROOM;

void create()
{
	set("short","碑刻");
	set("long",
@LONG
这里保存着”韩退之投书处”的一块碑刻，上面据说还写着那篇所谓的韩
愈的遗书。还有一块题刻，是一部的“苍龙岭观韩退之大哭辞家赵文备百岁笑
韩处”的碑刻。传说李肇在《国史部》中记载着韩愈的怯弱，山西百岁老人赵
文备观看了韩愈投书处，却放声大笑。遂在“韩退之投书处”旁有此题刻。
LONG);
         set("exits", ([ /* sizeof() == 2 */
		"southdown"  : __DIR__"longtou",
		"up": __DIR__"jiangjun",
		"south":__DIR__"zhandao1",
		]));
	set("outdoors","huashan"); 
	setup();
	
}
int valid_leave(object me,string dir)
{
	if(userp(me) && dir=="up")
        if(me->query_skill("dodge")<200
	|| random(4))
	{
	     me->receive_wound("kee",50,me);
	     return notify_fail("你费力的在山路上走着，一不小心摔倒了，好疼啊。\n");
	 }
	 return 1;
}
