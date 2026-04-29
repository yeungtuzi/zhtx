// XieXun.c
// yeung

#include "ansi.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

string ask_yuanzhen();

void create()
{
    set_name("谢逊", ({"xie xun", "xie", "xun", }));
	set("long",
        "他是一位身材魁伟异常的的老者，身穿一件白布长袍。\n"
        "他满头黄发，威风凛凛，真如天神一般，只是两只眼睛并不睁开。\n"
	);

	set("title","明教护教法王" NOR);
	set("nickname", HIY "金毛狮王" NOR);
	set("gender", "男性");
	set("attitude", "peaceful");

	set("age", 63);
	set("shen",-1000000);
	set("str", 100);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("cor", 100);

	set("max_kee", 3500);
	set("max_gin", 1500);
	set("max_sen", 1500);
	set("force", 6000);
	set("max_force", 3000);
	set("force_factor", 150);

	set("combat_exp", 900000);
	set("score", 800000);

    	set_skill("force", 160);
	set_skill("dodge", 140);
	set_skill("parry", 140);
	set_skill("cuff", 200);
	set_skill("taxue-wuhen",150);
    	set_skill("qishang-quan", 180);

	map_skill("force", "moni-xinfa");
	map_skill("dodge", "taxue-wuhen");
	map_skill("cuff", "qishang-quan");
    	map_skill("parry", "qishang-quan");

	prepare_skill("cuff","qishang-quan");

	set("inquiry",([
		  "成昆" : "成昆是我的师傅，也是我不共戴天的仇敌。\n如果你能帮我找到他，我便为你做牛做马也是甘愿。\n",
		  "黛绮丝" : "她是我教的四大法王之首：紫衫龙王，不过失踪很久了。\n",
                  "圆真" : (: ask_yuanzhen :),
	]));

	set("chat_chance", 2);
	set("chat_msg", ({
		HIR"谢逊咬牙切齿地咒骂：成昆你这奸贼，便是逃到天涯海角，我也要把你碎尸万段！\n"NOR,
		"谢逊喃喃自语：好多年没见，不知道紫衫妹子现在如何了？\n",
		"谢逊叹了口气：听说波斯总教派了三个使者捉拿失贞圣女......\n",	
	}) );

	create_family("明教",36,"弟子");

	setup();

}

int accept_object(object me, object obj)
{
	if(obj->query("for_xiexun"))
	{
		destruct(obj);
		me->set_temp("marks/xiexun",1);
        	command("thank "+me->query("id"));
		command("whisper "+me->query("id")+" 大恩无以言报，我就指点你去见黛绮丝吧，也许她能代我酬谢于你。\n");
		return 1;
	}
	return 0;
}

string ask_yuanzhen()
{
	this_player()->set_temp("marks/yuanzhen",1);
	return "少林寺的臭贼秃，我看他不象什么好东西。\n";
}

#include "fawang.h"





