// YangXiao.c
// by yeung

#include "ansi.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;


void create()
{
    	set_name("杨逍", ({"yang xiao","yang","xiao",}));
	set("long",
        "他是一位中年书生，身穿白布长袍。\n"
        "他相貌俊雅，只是双眉略向下垂，嘴边露出几条深深的皱纹，不免略带衰老凄苦\n"
        "之相。他不言不动，神色漠然，似乎心驰远方，正在想什么事情。\n"
	);

	set("title","明教"+YEL"光明左使" NOR);
	set("gender", "男性");
	set("attitude", "peaceful");
	
	set("age", 42);
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_kee", 3000);
	set("kee", 3000);
	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 100);
	set("combat_exp", 2000000);
	set("score", 10000);

	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("sword", 180);
	set_skill("literate", 180);
	set_skill("strike" , 180);


	set_skill("moni-xinfa", 180);
	set_skill("taxue-wuhen", 180);
	set_skill("xiaoyao-jian", 180);
	set_skill("xiaoyao-zhang", 180);

	map_skill("force", "moni-xinfa");
	map_skill("dodge", "taxue-wuhen");
	map_skill("parry", "xiaoyao-jian");
	map_skill("sword", "xiaoyao-jian");
	map_skill("strike", "xiaoyao-zhang");

	prepare_skill("strike", "xiaoyao-zhang");

	create_family("明教",35,"弟子");

	setup();

        carry_object(__DIR__"obj/gangjian")->wield();
	carry_object(__DIR__"obj/baipao")->wear();
	carry_object("/d/mingjiao/npc/obj/tieyanling")->wear();

        set("chat_chance_combat", 20);  
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "yinfengdao" :),
                (: exert_function, "recover" :),
        }) );

}

int accept_object(object me, object obj)
{
	if(obj->query("xiaoyao_du"))
	{
		destruct(obj);
		me->set_temp("marks/jinhuayinye",1);
		command("say 咦，你怎么会有这东西。这是我们逍遥二仙的独门毒药，江湖中人闻风丧胆。");
		command("say 不过，我已经很久没用过这毒了。");
		return 1;
	}
	return ::accept_object(me,obj);
}

#include "shizhe.h"
int valid_bribe(object who,int val) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 什么，你想贿赂我吗？！\n",who);
        return(0);
}

