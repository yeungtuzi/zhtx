// /d/xizang/huzhong.c

inherit ROOM;

void create()
{
        set("short","圣湖");
        set("long",@LONG
眼前就是著名的圣湖，碧蓝的湖面倒影着蓝天和白云，浩淼的水面
让人心旷神怡。远处金碧辉煌的雪山寺清晰可见，再远处是几座延绵的
大雪山，其中最高大的是神山，相传山中有神仙居住。雪山中融化的雪
水都汇入湖中。
LONG
        );

        set("resource/water",1);
        set("outdoors","xizang");

	set("objects", ([
		__DIR__"npc/fish" : random(4),
	]));
        setup();
}
// addaction swim
// to hubian 1-4
// improve force and swim

void init()
{
	add_action("do_out", "out");
        call_out("do_drown", 1, this_player());
}

int do_out()
{
	object me;
	me=this_player();
	if(me->query_skill("swimming", 1) < 30)
		me->improve_skill("swimming", 
			10+random(me->query("con")));
	message_vision("$N带着一身的水从圣湖里爬上来.\n", me);
	if(me->query_skill("force") < 100 ) {
        if ((me->query_con()+me->query_kar()) < random(31))
	me->apply_condition("ganmao", me->query_condition("ganmao")+10);
	message_vision("$N感到湖水十分清凉.\n", me);
	me->improve_skill("force", 10+random(me->query("con")));
	}
        me->move(__DIR__"hubian1");
   remove_call_out("do_drown");
	return 1;
}

void do_drown(object me)
{
	int amount;
	message_vision("一个浪头打来,$N一不小心呛了口湖水!\n", me);
	amount= -1*(100-me->query_skill("swimming", 1));
	if (amount<10) amount = 10;
	me->add("kee", amount);
        call_out("do_drown", 5, me);
}
