// /d/xizang/npc/hujinxiu.c
// 胡金袖

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

string ask_me();
void create()
{
	set_name("胡金袖", ({ "hu jinxiu", "hu", "jinxiu" }) );
	set("gender", "女性" );
	set("age", 32);
	set("nickname", HIC"身轻如燕"NOR);
	set("long", @LONG
    她是卜鹰的搭档兼情人胡金袖,据说卜鹰开店的钱就是从她那里借来的,她
现在鹰记商号内管账,顺便也卖一些杂货.
LONG
);
	set("str", 21);
	set("per", 28);
	set("combat_exp", 1000000);
	set("attitude", "friendly");
	set("env/wimpy", 70);
        set("inquiry", ([
                "宝藏": "鹰哥正在招募寻宝者,只要找到宝藏大家就都不用受穷了.\n",
                "传说": "就是昆仑之墟的传说啦.\n",
            	"帮助": (: ask_me :),
        ]) );
/*
	set("vendor_goods", ([
		"玉戒指": __DIR__"obj/jade3",
//		"蛇药"  : OBJ_DIR"medicine/snake_drug",
//                "仙豆"  : __DIR__"obj/bean",
//                "皮衣"  : OBJ_DIR"clothes/leather",
		"弯刀"	: __DIR__"obj/roundblade"
	]) );
*/	
	set("max_atman", 1000);
        set("atman", 1000);
        set("atman_factor", 3);
        set("max_force", 2000);
        set("force", 4000);             
        set("force_factor", 30);
        set("max_mana", 1000);
        set("mana", 1000);
        set("mana_factor", 3);
	set_skill("literate", 100);
        set_skill("parry", 200);
        set_skill("dodge", 300);
        set_skill("force", 200);
        set_skill("flysteps", 290);
        set_skill("fireforce", 200);
        set_skill("cloudhand", 200);
        set_skill("move", 200);
        set_skill("unarmed", 200);
        map_skill("force", "fireforce");
        map_skill("dodge", "flysteps");
        map_skill("move", "flysteps");
	map_skill("parry", "cloudhand");
        map_skill("unarmed", "cloudhand");

//        create_family("黑道盟", 6, "巡查使");

	set("class", "engineer");
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
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
			command("smile");
			say( "胡金袖笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，又何贵干啊? \n");
			break;
		case 1:
			command("xixi "+ob->query("id"));
			break;
		case 2:
			command("face "+ob->query("id"));
			break;
	}
}

string ask_me()
{
        object who, ob;
        who = this_player();
        if (who->query("marks/昆仑之墟") && 
		!who->query("marks/givengiftsbyhu")) {
		ob=new(__DIR__"obj/tent");
		ob->move(who);
		ob=new(__DIR__"obj/sleepbag");
		ob->move(who);
		who->set("marks/givengiftsbyhu", 1);
                return "这些东西留在我这里无用,不如送给你吧.\n";
	}
        return "自力更生方能得到幸福美好的未来.\n";
}
