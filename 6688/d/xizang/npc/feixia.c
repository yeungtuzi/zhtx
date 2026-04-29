// /d/xizang/npc/feixia.c
// modified by mscat
// master.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("蓝岚", ({ "lan lan", "lan", "feixia" }) );
	set("nickname", HIC"雪山飞侠"NOR);
	set("gender", "男性");
	set("age", 48);
	set("long",
		"雪山飞侠在雪梅谷苦练武功多年，练成一手绝世刀法。\n"
		"由于多年隐居山谷性格孤辟，下手极狠，最好不要惹他。\n"
            );
	set("attitude", "peaceful");

	set("str", 30);
	set("int", 24);
	set("cor", 30);
	set("cps", 30);
        set("per", 30);

	set("force", 2000);
	set("max_force", 2000);
	set("force_factor", 200);

	set("combat_exp", 10000000);
	set("score", 200000);
        set("bellicosity",300);
	set("env/wimpy", 50);
	
	set("chat_chance", 5);
     	set("chat_msg", ({
                "飞侠叹口气说道: 想当年... \n",
		(: random_move :),
		"飞侠露出痛苦的表情,不知道想起什么往事...\n"
	}) );

	set("inquiry", ([
		"当年" : "想当年老夫纵横天下,快意恩仇,只可惜....",
		"小梅" : (: ask_me :),
		"宝藏" : "有关宝藏的传说是骗人的,都是骗人的!",
		"1717" : "你怎么也知道1717?!你是哪里来的?",
		"卜鹰" : 
		"这家伙不是什么好人,到处招募寻宝者,却没见哪个人得宝回来",
		"铁笑" : "他就是所谓的阿铁,这家伙....哼!",
		"流星雨": "不许在我面前提他!!",
		"mud"  : "你现在就在泥潭里,快快quit!",
		"泥潭" : "你现在就在泥潭里,快快quit!"
	]));

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
                (: exert_function, "recover" :),
	}) );

	set_skill("unarmed", 500);
	set_skill("blade", 500);
	set_skill("force", 500);
	set_skill("parry",500);
        set_skill("dodge",500);
	set_skill("perception", 150);
        set_skill("cuixue-blade",500);
	set_skill("meixiangforce", 500);
        set_skill("move",500);
        set_skill("literate",200);
        set_skill("lanhuazhang",500);
        set_skill("feihua-step",500);

	map_skill("unarmed", "lanhuazhang");
	map_skill("force", "meixiangforce");
        map_skill("dodge","feihua-step");
	map_skill("blade", "cuixue-blade");
	map_skill("move", "feihua-step");
	map_skill("parry", "cuixue-blade");
       
	create_family("雪梅洞", 2, "隐者");
	set("class", "legend");

	setup();
        carry_object(OBJ_DIR"cloth")->wear();
	carry_object(__DIR__"obj/snowblade")->wield();
}

void attempt_apprentice(object me)
{
        if(me->query("combat_exp")<500000){
          command("say 你的经验还不够，再多练些年吧。");
          return;
        }
	if(!me->query("marks/xiaomei")){
	  command("say 这位"+ RANK_D->query_respect(me)+ 
		"武功高强,他日前途无量,还是另投明师吧.\n");
	  return;
	}
               command("smile");
		command("say 我本来是想收你的,可是我功夫太高了,如果收了你会破坏平衡.,巫师一定会把我改面,所以还是算了吧,哈哈~~~ ");
//               command("recruit "+me->query("id"));
//          me->set("betrayer",0);
               return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "legend");
}

string ask_me()
{
	if(this_player()->query("marks/xiaomei"))
		return "多谢你让我们父女团聚,她现在很好.\n";
	return "小梅是我的女儿,她失踪很久了.\n";
}
