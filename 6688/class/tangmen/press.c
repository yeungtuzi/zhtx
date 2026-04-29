//press.c
#include <ansi.h>

inherit NPC;
void use_poison();         
void use_dart(); 
void heal();

void create()
{
        set_name("巫夜", ({ "wu ye", "press" }) );
        set("title",HIR"唐门"NOR+GRN"五代女弟子"NOR);
	set("ZH_player","00001");
        set("nickname", RED"蜀中女毒怪"NOR);
        set("gender", "女性");
        set("age", 34);
        set("long", 
        	"她是方柔的爱徒，当今武当真人无记的爱妻。\n"
        	"原本是一天真可爱的小女侠, 后来不知为何性情大变,\n"
        	"毒杀了众多前来唐门挑衅之人, 在江湖上结了众多仇\n"
        	"家。方柔怕她在外面行走危险, 特招回身边, 一来修\n"
        	"习高深武学, 二来便于就近保护。\n"
        );

        set("attitude", "peaceful");
        set("class", "legend");
        set("str", 29);
        set("cps", 15);
        set("int", 29);
        set("cor", 25);
        set("con", 29);
        set("spi", 21);
        set("per", 25);
        set("kar", 10);
                                        
        set("kee",500);
        set("max_kee", 500);
        set("gin",200);
        set("max_gin", 200);
        set("sen",200);
        set("max_sen", 200);
        set("atman", 200);
        set("max_atman", 200);
        set("mana", 200);
        set("max_mana", 200);

        set("force", 600);
        set("max_force", 600);
        set("force_factor", 85);

        set("combat_exp", 470000);
        set("score", 2000);
        set("shen_tyep",-1);

        set_skill("force", 101);
        set_skill("sword", 101);
        set_skill("throwing", 101);
        set_skill("parry", 101);
        set_skill("dodge", 131);                            
        set_skill("move", 40);
        set_skill("strike",50);
        set_skill("dugong", 80);
        set_skill("literate", 100);

        set_skill("sunv-xinfa", 120);
        set_skill("yuenv-jian", 101);
        set_skill("tiannv-sanhua", 83);
        set_skill("taxue-wuhen", 118);
        set_skill("tangmen-duzhang",60);

        map_skill("dodge", "taxue-wuhen");
        map_skill("move", "taxue-wuhen");
        map_skill("force", "sunv-xinfa");
        map_skill("sword", "yuenv-jian");
        map_skill("parry", "yuenv-jian");   
        map_skill("strike", "tangmen-duzhang");
        map_skill("throwing", "tiannv-sanhua");

        prepare_skill("strike","tangmen-duzhang");

        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                "巫夜脚步轻移，翩翩地转了几个圈，回眸一笑。\n",
                "巫夜左手一扬，从袖中发出一颗毒蒺藜。\n",
                (: use_poison :),              
                (: use_dart :),
                (: heal :),
                (: perform_action , "throwing.sanhua" :)
        }) );

        create_family("唐门", 5, "弟子");

        set_temp("apply/defense", 20);
        set_temp("apply/attack", 20);

        setup();
        carry_object("/obj/weapon/gangjian")->wield();
        carry_object("/d/tangmen/obj/skirt")->wear();

}

void heal()
{
        object ob=this_object();

        if (ob->query("kee") < ob->query("eff_kee"))
        {
                command("exert recover");
                return;
        }

        if (ob->query("gin") < ob->query("eff_gin"))
                command("exert regenerate");

        return;
}

void use_poison()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

        if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
                {
                ob->apply_condition("tm_poison", random(7)+ob->query_condition("tm_poison"));    
                tell_object(ob, "你觉得脸上一痒，似乎有什麽东西，伸手一摸却什麽也没有。\n");
		ob->update_condition("tm_poison",random(2));
        }
        return ;
}

void use_dart()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

        if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
                {
                ob->set("kee", ob->query("kee")-40);    
                message_vision( "$N觉得身上一痒，伸手一摸，原来被巫夜的毒蒺藜打中了。\n",ob);
                ob->apply_condition("tm_poison", random(7)+ob->query_condition("tm_poison"));    
		ob->update_condition("tm_poison",random(2));
        }
        return ;
}

void init()
{
        add_action("do_killing", "kill");
}

int do_killing(string arg)
{
        object player, victim;
        string name;
        player = this_player();
        if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
        {
                name = victim->name();
                if( name == "方柔")
                {
                message_vision(RED "$N大喊一声:大胆狂徒, 敢害我师傅, 我跟你拼了!\n" NOR, this_object());
                this_object()->kill_ob(player);
                player->kill_ob(this_object());
                return 0;
                }
                return 0;
        }
        return 0;
}
