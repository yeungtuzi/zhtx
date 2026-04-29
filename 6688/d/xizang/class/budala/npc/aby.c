// d/xizang/class/budala/npc/aby.c

#include <ansi.h>
inherit NPC;
void check_sitting(object ob);

void create()
{
	set_name(HIM"小黛"NOR, ({"aby","abyi","daidai", "xiaodai", "dai"}));
	set("gender", "女性" );
	set("age", 15);
	set("per", 33);
	set("attitude", "peaceful");
	set("long", 
		"她是贩卖鲜花茶水和零食的女孩子小黛,也有不少人叫她黛黛.\n");
	set("combat_exp", 5111);
	set_skill("unarmed", 20);

	setup();
	carry_object(OBJ_DIR"cloth")->wear();
}

void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(5) ) {
		case 0: command("say  小黛轻声叫着: 卖花,卖花....\n"); break;
		case 1: command("say 花生米要吗? 茶水要吗?"); break;
		case 2: command("say 来一杯香茶吧"); break;
		case 3: command("say 各种小吃糕点,各种糖果,鲜花,茶水....");
			break;
		case 4: command("shake");
			command("say 没人想买我的东西吗?");
			break;
	}
	this_object()->check_sitting(ob);
	return;
}

void check_sitting(object ob)
{
	object goods;

	if( !ob || environment(ob) != environment() ) return;
	if(!ob->query_temp("拉萨邸报馆")) {
		command("say 这位"+ RANK_D->query_respect(ob) +"请坐请坐");
	} else {
		switch( random(3) ) {
	case 0 :
		if(ob->query("water")>=ob->max_water_capacity()) break;
		else {	
		command("say 这位"+ RANK_D->query_respect(ob)+"请用茶");
		goods=new(__DIR__"obj/tea");
		goods->move(ob);
		ob->add_temp("拉萨邸报馆",1);
		break; }
	case 1 :
		if(ob->query("food")>=ob->max_food_capacity()) break;
		else {
		command("say 这位"+ RANK_D->query_respect(ob) +
			"看起来有些饿了,吃点东西吧?");
		goods=new(__DIR__"obj/food");
		goods->move(ob);
		ob->add_temp("拉萨邸报馆",1);
		break; }
	case 2 :
		command("say 这位"+ RANK_D->query_respect(ob) +
			"买把鲜花吧?");
		goods=new(__DIR__"obj/flower");
		goods->move(ob);
		ob->add_temp("拉萨邸报馆",1);
		break;
		}
	}
	call_out("check_sitting", 3+random(20), ob);
}
