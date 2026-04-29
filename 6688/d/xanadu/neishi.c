// 幽明山庄
// by yeung. All rights reserved.

#include <ansi.h>

inherit "/std/room/doom.c";

string look_book();

void create()
{
	set("short","栖霞馆");
	set("long", @TEXT
	这里是女主人小话日常起居的地方，虽然收拾得一尘不染，而且颇为
雅致，可小话整天忙于打打杀杀，并没有多少时间在这里。据说庄主曾有多蓄
内宠之意，不过只要看看墙上挂着的毒药囊和刀枪就可以知道流星雨只怕这辈
子是没戏了。靠窗的地方是一个梳妆台，镜子前面是一本翻开的书(Book)。还
有一个奇形怪状的轮盘放在旁边，也许是小话从娘家唐门弄来的什么古怪机关。
TEXT
	);

	set("exits", ([ /* sizeof() == 2 */
	  "south" : __DIR__"hall",
	]));
/*
	set("objects", ([
			__DIR__"npc/obj/shigu" : 4,
		])
	);
*/	
        set("seed1",random(10)+1);
        set("seed2",random(20)+21);
        set("seed3",random(50)+51);
        set("seed4",random(100)+101);

	set("item_desc", ([
		"book": (: look_book :),
	]) );


	set("no_fight",1);
	set("no_magic",1);
	set("no_poison",1);
	setup();
}                               

int init()
{
	add_action("do_turn","turn");
	::init();
}                                      

string look_book()
{
	string result;
	object me;     
	int puzzle;
	
	me = this_player();
	result = "\n这本书上没有什么值得注意的东西。\n";
	if( puzzle = me->query_temp("marks/xanadu_hall2") )
	{	
		me->set_temp("marks/xanadu_hall3",1);
		result += "就在你失望地要放下书的时候，里面掉出来一张字条，上面写道：\n"
			  "相公，魔师与覆雨剑决战接天楼，黑榜高手尽集于此，万勿错过！\n"	
			  "拨动轮盘就有一道门可以进去。                    小话。\n";
		result += "对了，还有，轮盘的数字嘛，要考考你...\n";
		result += "这个数，它除"+query("seed1")+"余"+puzzle%query("seed1")+"，";
		result += "它除"+query("seed2")+"余"+puzzle%query("seed2")+"，";
		result += "它除"+query("seed3")+"余"+puzzle%query("seed3")+"，";
		result += "它除"+query("seed4")+"余"+puzzle%query("seed4")+"\n";
	}                                                                       
	return result;
}

int do_turn(string arg)
{
	object me;
	int answer,puzzle;

	me = this_player();
	if(!arg)             
		return notify_fail("你要把轮盘转到哪一个数字上？\n");        
	if( me->query("force") < 500 )
		return notify_fail("你的内力不够，拨不动轮盘。\n");
	if( !(answer = (int)arg) || !(me->query_temp("marks/xanadu_hall3")) )
		return notify_fail("你瞎转什么？\n");		
	me->add("force",-150);
	message_vision("$N把轮盘拨到了"+arg+"的位置\n",me);		   
	puzzle = (int)me->query_temp("marks/xanadu_hall2");
	if( ("X"+puzzle+"X") == ("X"+answer+"X") )
	{
		write("一阵机关之声响过之后，你来到了一个新的地方。\n");
		me->delete_temp("marks/xanadu_hall2");
		me->delete_temp("marks/xanadu_hall3");
		me->move(__DIR__"lou0");
		tell_room(this_object(),"墙上突然开了一道门，"+me->query("name")+"毫不犹豫地走了进去。\n");
	}
	else
		message_vision("可是什么都没有发生。\n",me);			
	return 1;
}