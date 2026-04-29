// /d/xizang/npc/xiaomei.c
// 小梅
//
// by mscat

#include <ansi.h>
inherit NPC;
//inherit F_MASTER;

string ask_me();

void create()
{
	set_name(HIM"小梅"NOR, ({ "xiao mei", "xiaomei", "mei" }) );
	set("gender", "女性");
	set("age", 19);
	set("long", @LONG
    她就是铁笑苦苦等待的情人小梅,雪山飞侠蓝岚的女儿.
LONG
            );
	set("attitude", "peaceful");

	set("str", 12);
	set("int", 29);
	set("cor", 20);
        set("per", 30);
	set("spi", 31);

	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 20);

	set("combat_exp", 1000000);
	set("score", 2000);
	set("env/wimpy", 70);
	
	set("inquiry", ([
		"学画" : (: ask_me :),
		"宝藏" : "宝藏倒是没有,不过有些奇怪的石头,可以拿来作雕刻",
		"卜鹰" : ({ (: command("face") :),
				"鹰哥是个很好玩的家伙,嘻嘻..." }),
		"铁笑" : ({ (: command("blush") :),
				"看见他代我向他问好" }),
		"阿铁" : ({ (: command("blush") :),
                                "看见他代我向他问好" }),
	]));

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
                (: exert_function, "recover" :),
	}) );

	set_skill("unarmed", 50);
	set_skill("force", 50);
	set_skill("parry",50);
        set_skill("dodge",100);
	set_skill("perception", 50);
        set_skill("sevencolor", 100);
	set_skill("drawing", 100);
	set_skill("music", 100);
	set_skill("dancing", 100);
        set_skill("move",50);
        set_skill("literate",200);
        set_skill("lanhuazhang",50);
        set_skill("feixue-quan", 100);
        set_skill("feihua-step",50);

        map_skill("unarmed", "feixue-quan");
        map_skill("force", "sevencolor");
        map_skill("dodge","dancing");
	map_skill("move", "dancing");
        map_skill("parry", "feixue-quan");
      	set("class", "legend");

	create_family("雪梅洞", 3, "隐者");

	setup();
        carry_object(OBJ_DIR"cloth")->wear();
}

int recognize_apprentice(object ob)
{
        if( !ob->query("marks/xiaomei") ){
		command("face");
                say("小梅说道:我没什么可教你的啦!\n");
                return 0;
        }
        return 1;
}

string ask_me()
{
	if(this_player()->query("marks/xiaomei")) {
		command("face");
		return "你喜欢画画儿是吧?我也喜欢,大家一起玩儿.\n";
	}
	return "画画儿很没意思的,不如去学武功纵横天下好了.\n";
}
