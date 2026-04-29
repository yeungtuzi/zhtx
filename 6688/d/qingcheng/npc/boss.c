#include <ansi.h>
inherit NPC;
string ask_me(object who);
void create()
{
        set_name("酒店老板", ({"inn boss","boss"})  );
        set("gender", "男性" );
        set("age", 38);
        set("str", 20);
        set("cor", 27);
        set("cps", 25);
	set("shen_type", -1);      
        set("max_force", 400);
        set("force", 500);
        set("force_factor", 30);

       
        set("long",@LONG
自从林平之接管镖局以后,他就来到这里开了个酒店,没有人知道他的来历.
他的为人挺不错的,特别对本镇的人.因此酒店的生意还算可以。
LONG);

       

        set("combat_exp", 200000);
        set("score", -10000);

        set("chat_chance_combat", 60);

        set_skill("unarmed", 60);
        set_skill("parry", 80);
        set_skill("dodge", 40);
        set_skill("sword", 80);
        set_skill("force", 50);
        set_skill("qingcheng-steps", 40);
        set_skill("qingcheng-force",50);
        set_skill("pine-sword", 80);

      map_skill("force","qingcheng-force");
      map_skill("sword", "pine-sword");
      map_skill("dodge", "qingcheng-steps");
      map_skill("parry", "pine-sword");     
        set("inquiry", ([
                "qingcheng": (: ask_me :),
                "青城派" : (: ask_me :)
        ]) );

        setup();
        add_money("silver", 40);
        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/sword")->wield();
}
string ask_me(object who)
{
	int i;
	object *ob;
	if( query("revealed") ) {
		if( is_killing(who) ) return "你既然看出了我的武功，今日休想活命！\n";
		else {
			kill_ob(who);
			who->fight_ob(this_object());
			return "不错，老子就是青城派的奸细！纳命来！\n";
		}
	}

	if(random(10) < 7)
		return "你问这个干吗？\n";
	
	set("title", HIR "青城奸细" NOR);
	message("vision",
		HIY "酒店老板眼中突然放出异样的光芒，颤声说道：看来...你都知道了？\n\n"
		"酒店老板大喝一声，叫道：既然如此，老子今天豁出去了，纳命来！\n" NOR,this_player() );
	set("pursuer", 1);
	set("attitude", "aggressive");
	set("vendetta/authority", 1);
	set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :)
	}) );
	set("bellicosity", 10000);
	
	ob = all_inventory(environment());
	for(i=sizeof(ob)-1; i>=0; i--) {
                if( !ob[i]->is_character() || ob[i]==this_object() ) continue;
		kill_ob(ob[i]);
		ob[i]->fight(this_object());
	}
	set("revealed", 1);
        carry_object(__DIR__"obj/key");
        
}

