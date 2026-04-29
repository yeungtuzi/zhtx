
inherit NPC;
#include <ansi.h>

int ask_shu();

void create()
{
	set_name("仆役", ({ "pu yi", "pu","yi" }) );
	set("gender", "男性" );
	set("age", 25);
	set("int", 28);
	set("long","\n这是个仆役打扮的年青人，两眼乱转，四处看个不停,好象害怕什么。\n");
	set("attitude", "peaceful");
        set("combat_exp",10000+random(500000));
	set("chat_chance", 3);
	set("chat_msg", ({
	"仆役得意的说：这个你可千万不要告诉别人啊！\n",
	"仆役对丫环低声说道: 我知道佛堂里的秘密。\n",
	}));
        set("inquiry", ([
                "佛堂" :  "你也知道佛堂里有书？\n",
                "书" :   (: ask_shu :),
                "四十二章经" :  (: ask_shu :),
                "秘密" :  (: ask_shu :),
                "钥匙" :  (: ask_shu :),
	       ]) );
	setup();
	carry_object("/obj/cloth")->wear();
}


int accept_object(object who, object ob)
{
	if (ob->query("money_id") && ob->value() >= 100000) 
	{
		who->set_temp("money2_paid",1);
		return 1;
	}
	return 0;
}

int ask_shu()
{
	if (this_player()->query_temp("money2_paid"))
		{
	this_player()->delete_temp("money2_paid");
	say("仆役说道：地板下面有暗锁，钥匙在佛像左耳里。\n");
	say("仆役又说：货真价实，不会骗你的。实在不行你回头来找我。\n");
	return 1;
		}
	say("仆役说道：干什么也得先交钱啊。\n");
	say("仆役又说：我花了一年多时间才查到这件物事的所在，\n"+
	"你这一千两银子，可不是好赚的。\n");
	return 1;
} 

