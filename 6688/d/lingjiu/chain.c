// Room: /d/lingjiu/rock.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "接天桥");
	set("long", @LONG
这里说是接天桥,其实不过是一根铁索罢了。铁索连着山涧的
两岸断魂崖和仙愁岭，铁索下雾气蒸笼，终年不散！从这里掉
下去当真是死无葬身之地。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"rock",
  "north" : __DIR__"xianchou",
]));
	set("no_clean_up", 0);
	set("outdoors", "lingjiu");

	setup();
}

void init()
{
	this_player()->start_busy(1);

	add_action("do_help", "help!");
	add_action("do_follow", "follow");
}

int do_follow(string arg)
{
	if( this_player()->query_temp("go_dir") && arg)
		return notify_fail("人都挂在了半空，还想跟上别人？\n");
}
		
int do_help(string arg)
{
	object me;
	int i;

	me = this_player();
	i = (int)me->query_temp("go_dir");
	if( i == 0 )
		return notify_fail("没事瞎嚷嚷什么！\n");			
	if( random(5) == 0 ){
		me->delete_temp("go_dir");
		message_vision("一位老婆婆沿着铁链飞也似的奔了过来，将$N往胁下一夹，送到了对岸。\n", me);
		message_vision("老婆婆对$N说道：“下次小心啦！”\n", me);
		if( i == 1 )
			me->move(__DIR__"rock");
		else me->move(__DIR__"xianchou");
		return 1;
	}
}
	
int valid_leave(object ob, string dir)
{
	int move_level;
	object room;

	if( ob->query("mark/ding_chushi") == 5
	&& ob->query("mud_age") > ob->query("mark/waiting_ding") + 86400){
		ob->delete("mark/waiting_ding");
		message_vision(HIR"\n\n哪里跑！！！\n"NOR, ob);
		new(CLASS_D("xingxiu")+"/ding")->move(environment(ob));
		tell_object(ob, "你正欲离开，只听见背后有人喊：“哪里跑！”你回头一看，此人不是别人，正是星宿老怪"+HIR+"丁春秋！\n"NOR);
		message_vision(HIR"$N又惊又怒，不提防丁春秋一招打在你的前胸，$N哇地吐出一口鲜血，在铁链上再也站立不住，一头向涧里栽了下去！！！\n\n"NOR, ob);
		ob->apply_condition("fushi-du", 20);
		ob->receive_wound("kee", ob->query("max_kee")/2);
		tell_room(environment(ob), "丁春秋嘿嘿奸笑：“三十年前，无崖子从这里掉下去，我今天就送你去见无崖子他老人家。”\n", ob);
		tell_object(ob, "你隐隐听到上面几句话传来：“三十年前，无崖子从这里掉下去，我今天就送你去见无崖子他老人家，哈哈哈。。。”\n");
		tell_object(ob, "你心想，从这里跌下去，自是再无人世间的诸般烦恼，只是便宜了丁春秋这老贼，不免遗憾。\n");
		tell_object(ob, "\n\n迷迷糊糊之中，你只觉得你的身子先是一横，接着又象是碰到什么棉絮，后来又好象腰间被什么东西缠住了。。。。。。\n");
		ob->set("mark/ding_chushi", 6);
		ob->unconcious();
		if( !(room = find_object("/d/leigu/guli")) )
			room = load_object("/d/leigu/guli");
		ob->move(room);
		tell_room(room, HIY"\n你抬头一望，发现一个人影正笔直地从崖顶跌落下来！！！难道是想不开吗？\n\n"NOR);
		tell_room(room, HIR"左首老者使出绝顶神功乾坤大挪移，双掌变幻吞吐之际，只见那人已由直摔变为横飞，向着中间那老者撞去！\n"NOR);
		tell_room(room, HIR"中间那老者使出太极神功的卸字决，将来人的势道卸去一大半，同时双手画弧，在那人腰间轻轻一带，那人如箭般飞向右首的老者！\n"NOR);
		tell_room(room, HIR"右手那老者手一抖，已然多了一条软带，卷住了来人，跟着身子如陀螺般旋转起来，带着来人连转了数十道圆圈，终于软带脱手飞出，连着来人一起飞向一丛沼泽地。\n\n"NOR);
		tell_room(room, "耳听得噗嗵一声，来人跌落在地上，乱泥飞溅！\n\n");
		tell_room(room, "无名老者摇摇晃晃，眼看就要倒下！\n");
		tell_room(room, "无名老者摇摇晃晃，眼看就要倒下！\n");
		tell_room(room, "无名老者摇摇晃晃，眼看就要倒下！\n");
		return notify_fail("");
	}

	move_level = ob->query_skill("move");
	
	if( ob->query_temp("go_dir") )
		return notify_fail("别冒险了，赶紧喊救命吧！\n");
	if( dir != "south" && dir != "north" )
		return notify_fail("你想找死啊，有什么想不开的地方吗？\n");
	if( (move_level + random(move_level)) < 60 ){
		if( dir == "south" ) ob->set_temp("go_dir", 1);
		if( dir == "north" ) ob->set_temp("go_dir", -1);
		message_vision(HIY"$N身子一个不平衡，整个人就掉了下去，慌乱中$N双手抓住了铁链，结果整个人挂在了半空，来回摇荡！\n"NOR, ob);
		ob->start_busy(1);
		return notify_fail("你吓得魂飞魄散！\n");
	}	

	return ::valid_leave(ob, dir);
}
