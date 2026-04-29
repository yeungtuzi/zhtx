#include <ansi.h>
inherit NPC;



void create()
{
	set_name("鳌拜", ({
		"ao bai",
		"ao",
		"bai",
	}));
	set("long",
		"他就是满洲第一勇士，身穿一袭金边锦缎。他身材魁梧，\n"
		"相貌狰狞，太阳穴高高鼓起，似乎身怀绝世武功。\n"
	);

	set("nickname", CYN"满洲第一勇士"NOR);
	set("gender", "男性");
	set("attitude", "aggressive");

	set("age", 50);
	set("shen_type", -1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("max_kee", 1500);
	set("max_gin", 1500);
	set("force", 1500);
	set("max_force", 1500);
	set("force_factor", 50);
	set("combat_exp", 1500000);
	set_skill("force", 90);
	set_skill("hunyuan-yiqi", 90);
	set_skill("dodge", 90);
	set_skill("shaolin-shenfa", 95);
	set_skill("hand", 100);
	set_skill("parry", 100);
	set_skill("literate", 55);
//	set_skill("fengyun-shou", 90);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
//	map_skill("hand", "fengyun-shou");
//	map_skill("parry", "fengyun-shou");

//	prepare_skill("hand", "fengyun-shou");

        set("chat_chance_combat", 10);  
        set("chat_msg_combat", ({
                " 鳌拜怒道：你敢不让我睡觉，老子宰了你 ！\n",
                (: command("say 老子宰了你这" + RANK_D->query_rude(this_player())+"!\n") :),
		(: command("pain") :),
                      }) );
        setup();
      if(random(5)< 1)  carry_object(__DIR__"obj/anmenkey");
        carry_object(__DIR__"obj/jinduan")->wear();
        carry_object(__DIR__"obj/yaodai")->wear();
        add_money("gold",random(6));
}

void die()
{
        message("vision","\n鳌拜狂叫道：想不到我一世威名竟然毁于你手！\n",this_object());        	 
        message("vision","鳌拜顿了一顿，叹道：唉，只可惜我的那么多宝贝啊！\n",this_object());        	 
        message_vision("$N哀嚎一声，死了！\n", this_object());
        ::die();
}


