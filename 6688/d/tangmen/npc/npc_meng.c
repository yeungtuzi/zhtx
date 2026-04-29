// npc_meng.c
//last modified by pock 1998.07.25
#include <ansi.h>

inherit NPC;
inherit F_QUEST;
void use_poison();         
void use_dart(); 
void cui_poison();
void heal();

void create()
{
        set_name("唐梦", ({ "tang meng","tang","meng" }) );

        set("gender", "男性" );
        create_family("唐门", 4, "弟子");	
	set("title",YEL"唐门总护法"NOR);
        set("age", 51);
        set("long",@LONG

     他是唐门门主的哥哥，现任唐门总护法，负责保护唐门的安全,
  维护唐门的声誉。少年时代在外游历，14 岁回到家中聆听老母欧阳
  氏敏夫人的教诲，终成江湖一代名侠，被誉为妙手毒王。一生坎坷，
  命运多厄，常自孤独难眠，以“梦里幽情总伤心”，“心伤心流泪，
  梦醒梦难回 ”等自勉。中年时，终心灰意冷，带着一身深不可测的
  武功和一脸憔悴落寞的神情回到唐门担任起保家重任。

LONG
        );

        set("attitude", "peaceful");
	set("nickname",HIC"妙手毒王"NOR);
        set("chat_msg_combat", ({
                "唐梦说道: 你也未免太小看唐门了。\n",
                "唐梦右手一扬，从袖中发出一枚回旋镖。\n",
                (: use_poison :),              
                (: use_dart :),
		(: heal :),
                (: cui_poison :),
                (: perform_action , "throwing.sanhua" :)
		}));
       set("chat_msg", ({
	"唐梦喃喃自语道: 
         这世道，也太险恶了。\n",
                (: random_move :)
        }) );


        set("str", 59);
        set("int", 46);
        set("spi", 26);
        set("per", 28);
        set("cps", 26);
        
        set("force", 2326);
	set("atman",1667);
	set("mana",779);
        set("max_force", 2326);
	set("max_mana",398);
	set("max_atman",834);
        set("force_factor", 150);
        
        set("combat_exp", 3207764);
        
        set_skill("dugong", 200);
        set_skill("force", 180);
        set_skill("parry", 202);
        set_skill("dodge", 201);
        set_skill("literate", 200);
        set_skill("strike", 162);
        
        set_skill("mantian-huayu", 202);
        set_skill("tangmen-xinfa", 180);
        set_skill("tangshi-jian", 201);
        set_skill("taxue-wuhen",201);
	set_skill("throwing",201);
	set_skill("mantian-huayu",202);
	set_skill("unarmed",132);
	set_skill("sword",175);
	set_skill("move",181);
	set_skill("tiannv-sanhua",183);
	set_skill("tangmen-duzhang",182);

        map_skill("dodge", "taxue-wuhen");
        map_skill("force", "tangmen-xinfa");
        map_skill("sword", "tangshi-jian");
        map_skill("parry","mantian-huayu");
	map_skill("strike","tangmen-duzhang");
	map_skill("move","taxue-wuhen");
	map_skill("throwing","tiannv-sanhua");
	        
	prepare_skill("strike","tangmen-duzhang");

        setup();
	carry_object(__DIR__"obj/dart")->wield();
        carry_object(__DIR__"obj/dagger")->wield();
        carry_object(__DIR__"obj/jinyi")->wear();

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
                ob->apply_condition("tm_poison", random(10)+ob->query_condition("tm_poison"));    
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
                message_vision( "$N觉得身上一痒，伸手一摸，原来被唐梦的回旋镖打中了。\n",ob);
                ob->apply_condition("tm_poison", random(10)+ob->query_condition("tm_poison"));    
		ob->update_condition("tm_poison",random(2));
        }
        return ;
}

void cui_poison()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

	if( ob )	command("exert quickpoison "+ob->query("id"));

        return ;
}

void init()
{
	add_action("give_quest","quest");
        add_action("do_killing", "kill");
}

int do_killing(string arg)
{
        object player, victim;
        player = this_player();
        if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
        {

                if( userp(victim))
                {
		message_vision(YEL "$N道: 我平生最狠人pk的了.\n\n",this_object());
                message_vision(RED "$N大喊一声: 大胆狂徒, 敢在我面前漤杀无辜？!!!!!!!\n" NOR, this_object());
                this_object()->kill_ob(player);
                player->kill_ob(this_object());
		command( "follow "+player->query("id"));
                return 0;
                }
                return 0;
        }
        return 0;
}


                                      
                                                                     
