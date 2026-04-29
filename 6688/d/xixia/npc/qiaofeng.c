#include <ansi.h>

inherit NPC;

void ask_azhu();
void go_away(object me);

void create()
{
	set_name("萧峰", ({"xiao feng", "xiao", "feng"}));
        set("nickname", "北乔峰");
	set("gender", "男性");
	set("age", 31);
	set("title", "前丐帮帮主");
	set("rank_info/respect", "乔帮主");
	set("long", @LONG
萧峰就是前丐帮帮主乔峰，丐帮也由此盛极一时。后来因为他是契丹人，被迫
离开丐帮，几经辗转成了契丹南院大王。乔帮主胆识过人，为人慷慨豪迈，真英雄
也，只是天意弄人，注定一生坎坷。
LONG);

	set("attitude", "peaceful");
	
	set("str", 58);
	set("int", 35);
	set("con", 35);
	set("dex", 30);
	set("lea", 60);
	set("cor", 50);
	set("cps", 50);
	set("per", 30);

	set("max_kee", 6000);
	set("max_gin", 1000);
	set("max_sen", 1000);
	set("force", 7000);
	set("max_force", 3500);
	set("force_factor", 250);
	
	set("combat_exp", 5000000);

	set("bellicosity", 100);

	set("inquiry", ([
		"name": "乔帮主三字休要再提，在下一介契丹莽夫，萧峰是也。",
		"阿朱": (: ask_azhu :),
	]));

	set_temp("apply/attack", 110);
	set_temp("apply/defense", 110);
	set_temp("apply/armor_vs_force", 250);
	set_temp("apply/armor", 100);
	
	set_skill("force", 220); 
	set_skill("huntian-qigong", 220); 
        set_skill("strike", 220);
	set_skill("xianglong-zhang", 220); 
	set_skill("dodge", 220); 
	set_skill("xiaoyaoyou", 200); 
	set_skill("parry", 220); 
	set_skill("staff", 220); 
	set_skill("dagou-bang", 220); 
	set_skill("checking", 180);
	
	map_skill("force", "huntian-qigong");
	map_skill("strike", "xianglong-zhang");
	map_skill("staff", "dagou-bang");
	map_skill("dodge", "xiaoyaoyou");

	prepare_skill("strike", "xianglong-zhang");
	
	setup();

	carry_object("obj/cloth")->wear();

}

void init()
{
	object ob;

	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment()) return;
	command("hi " + ob->query("id"));
}

void ask_azhu()
{
	object me = this_object();

	message_vision("$N一深长叹。。。。。。\n", me);
	command("say 唉。。。。。。都是我害了阿朱。。。。。。");
	message_vision("$N神色黯然。。。。。。\n\n\n", me);
	call_out("go_away", 10, me);
}

void go_away(object me)
{
	if (!is_fighting()) {
		message_vision("$N悄然离去。。。\n", me);
		destruct(me);
	}
}
