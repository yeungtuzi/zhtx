// eelon.c

#include <ansi.h>

inherit "/u/z/zephyr/revengenpc.c";
inherit F_MASTER;
inherit F_QUEST;
inherit "/feature/challenge";

void use_poison();

void create()
{
        set_name("瑷伦", ({ "master eelon", "master", "eelon" }) );
        set("title","晚月庄的开山师祖");
        set("nickname",MAG"忘情人"NOR);
        set("gender", "女性");
        set("age", 63);
        set("long",
        "瑷伦是晚月庄的开山师祖\n"
        );
        set("attitude", "peaceful");
        set("class", "dancer");
        set("apprentice_available", 10);

        set("str", 30);
        set("int", 30);
        set("spi", 30);
        set("per", 30);
        set("cps", 30);
	set("no_get",1);

        set("force", 5000);
        set("max_force", 5000);
	set("force_factor", 100);
	set("kee",1000);
	set("max_kee",1000);

        set("combat_exp", 2000000);
        set("score", 200000);

         set("inquiry", ([
                "武学" : "武学博大精深，永无止境。\n",
                "往事" : "不要再提了。 \n",
       		"拜师" : "有志气的孩子,想拜我为师的，是真心吗?(accept test)？\n",
	 	"蓝止萍": "止萍她还好吧？这孩子，唉...。",
        ]) );
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                "瑷伦身形变幻,但动作优美,如轻歌曼舞。\n",
                "瑷伦用手扶了扶自己的发簪，像是怕被对手碰歪似地。\n",
                "瑷伦拾起地上一片落下的花瓣。\n",
                (: use_poison :),
                (: exert_function, "chillgaze" :),
        }) );
	set("shen_type",-1);

        set_skill("finger", 150);
        set_skill("sword", 100);
        set_skill("throwing", 150);
	set_skill("force", 200);
        set_skill("parry", 150);
        set_skill("dodge", 220);
        set_skill("literate", 100);
        set_skill("perception", 150);
        set_skill("whip", 200);
	set_skill("music",100);

        set_skill("stormdance", 220);
        set_skill("tenderzhi", 150);
        set_skill("iceforce", 200);
        set_skill("snowwhip", 200);
        set_skill("sword", 200);
        set_skill("snowshade-sword", 200);

        map_skill("dodge", "stormdance");
        map_skill("sword", "snowshade-sword");
        map_skill("finger", "tenderzhi");
	prepare_skill("finger","tenderzhi");
        map_skill("force", "iceforce");
        map_skill("whip", "snowwhip");

        create_family("晚月庄", 1, "太上庄主");

        set_temp("apply/defense", 100);

        setup();

        carry_object("d/latemoon/npc/obj/whip")->wield();
	carry_object("/d/latemoon/obj/deer_boot")->wear();
	carry_object("/d/latemoon/obj/blue_dress")->wear();
}

void init()
{
        ::init();
        add_action("do_accept", "accept");
        add_action("give_quest", "quest");
}


int do_accept(string arg)
{
        mapping guild;

        if( (string)this_player()->query("gender") != "女性" ) {
        command("say 我不收男弟子！");
                return 1;
        }
	else if( this_player()->query("family/family_name")!= "晚月庄") {
		command("say 你先去拜止萍吧。");
		return 1;
	}
        else {
		
        if( arg== "test" ) {
                say("\n忘情人说道，好孩子，小心了，这是第一招....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(), 
                        query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0 
                || !present(this_player(), environment())) {
                say("\n忘情人幽幽叹了一口气道: 好孩子,别勉强了. n");
                        return 1;
                }
                say("\n忘情人说道: 嗯, 这是第二招了....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(), 
                        query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0 
                || !present(this_player(), environment())) {
                        say("忘情人道：好孩子,别打坏了你....\n");
                        return 1;
                }
                say("\n忘情人说道：好了这最后一招可要接好....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(), 
                        query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0 
                || !present(this_player(), environment())) {
                        
                say("忘情人道：好孩子，能接我俩招，只可惜....\n");
                        return 1;
                }
                
say("\n忘情人轻轻抚摸着你的头发道: 很好，只要你好好学,它日成就不可限量\n\n");
                command("recruit " + this_player()->query("id") );
                return 1;
        }
        return 0;
 }
}


void use_poison()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

        if( ob->query_condition("rose_poison") ) return;

        tell_object(ob, 
"你觉得脸上似乎沾上了什麽东西，伸手一摸却什麽也没有。\n");
        if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
                ob->apply_condition("rose_poison", 20);
}
 
/*
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "dancer");
}
*/
