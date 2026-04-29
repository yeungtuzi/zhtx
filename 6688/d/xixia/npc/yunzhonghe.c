#include <ansi.h>

inherit NPC;

void create()
{
	set_name("云中鹤", ({"yun zhong he", "yun"}));
        set("nickname", HIR "穷凶极恶" NOR);
	set("title", "四大恶人");
	set("gender", "男性");
	set("age", 33);
	set("long", @LONG
此人排行四大恶人之末，好色成性，专干那些采花盗柳之事，淫贼之名
昭著武林，虽多次有正派人士欲除之而后快，无奈此人武功了得，轻功
尤佳，每次都让他逃之夭夭。 
LONG);
	set("attitude", "peaceful");
	
	set("int", 20);
	set("dex", 35);
	set("per", 20);

	set("max_kee", 1800);
	set("max_gin", 400);
	set("max_sen", 400);
	set("force", 1500);
	set("max_force", 1500);
	set("force_factor", 70);
	
	set("combat_exp", 750000);

	set("bellicosity", 100);
	set("wimpy", 35);

	set_temp("apply/armor", 30);
	
	set_skill("force", 100); 
	set_skill("tianmo-dafa", 100); 
        set_skill("unarmed", 220);
	set_skill("dodge", 170); 
	set_skill("move", 170); 
	set_skill("mo-shan-jue", 170); 
	set_skill("parry", 90); 
	set_skill("whip", 90); 
	set_skill("mo-bian-jue", 90); 
	
	map_skill("force", "tianmo-dafa");
	map_skill("whip", "mo-bian-jue");
	map_skill("parry", "mo-bian-jue");
	map_skill("dodge", "mo-shan-jue");
	map_skill("move", "mo-shan-jue");

	setup();
	
	carry_object(__DIR__"obj/tiezhao")->wield();
	carry_object("/obj/cloth")->wear();
	add_money("gold", 10);
}
 
void init() 
{
        object ob;

        ::init();

        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting",1,ob);
        }
}

void greeting(object ob)
{ 
        if (ob->query("gender") == "女性" && ob->query_per() > 25 
         && ob->query("age") < 22) { 
                command("say 啧啧，好漂亮的妞儿！"); 
                if (ob->query_skill("dodge") < 50) { 
                        message_vision("$N突然伸手在$n脸上摸了一把，真恶心死了！\n", this_object(), ob); 
                        tell_room(environment(), "你看到" + name() + "在调戏" + ob->name() + "，要上去制止吗？(kill yun)\n", ob); 
                } 
    	} 
} 

int accept_fight(object who) 
{ 
        if (who->query("gender") == "女性" && who->query("age") < 22) { 
                command("say 好啊！小姑娘找上门来啦，嘻嘻，来呀！"); 
                command("say 不过看你细皮嫩肉的，打坏了我会心疼死的！"); 
        	return 1; 
        } 
        else if (who->query("gender") == "男性") { 
                command("say 没有小姑娘陪，就想找老子打架？滚开滚开！"); 
                return 0; 
        } 
        else if (who->query("age") > 35) { 
                command("say 老子对老太太没有兴趣，走开走开！"); 
                return 0; 
        } 

	return ::accept_fight(who);
}
