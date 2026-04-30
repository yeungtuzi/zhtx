#include <ansi.h>
inherit NPC;
string *leave_msg = ({     
	YEL"林平之看到父亲走了过来，喜出望外地迎了上去，说道:爹!你回来了? \n",NOR
	WHT"林镇南爱慈的拍了拍林平之的头，说到:孩子，这么多年来，辛苦你了 .\n",NOR
	YEL"林平之道:爹，这些年你都去哪了?\n",NOR
	WHT"林镇南道: 说来话长，孩子，这里是个是非之地，我门赶快收拾东西，远走它方为妙。 \n",NOR
	YEL"林平之说道:好的，只要是爹你说的，我一定照办!\n",NOR
	WHT"林镇南说道: 这位" +RANK_D->query_respect(this_player())+",我宅中有一本武林密芨，留待有缘人，你可以找找看 .\n",NOR
	"林镇南和林平之收拾好东西，把过道封上，然后匆匆的离去了。\n",
	});	
string kill_passenger(object who);

void create()
{
        set_name("林平之", ({ "lin pingzhi","lin" }) );
        set("gender", "男性" );
 	set("shen_type",1);
        set("age", 25);
        set("str", 27);
        set("int", 29);
        set("per", 28);
        set("long", @LONG
林平之少年英雄,师从华山派.因为父亲的失踪而回到镖局总畴大计.
LONG
);
        set("attitude", "peaceful");

        set("combat_exp", 500000);
        set("bellicosity", 0);
        set("marks/林平之本人", 1);

        set_skill("sword", 150);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("hunyuan-zhang", 70);
        set_skill("huashan-shenfa", 80);

                        
        map_skill("dodge", "huashan-shenfa");
        map_skill("unarmed","hunyuan-zhang");
        setup();

        add_money("coin", 50); 
        carry_object("/obj/cloth")->wear();
       
}

int accept_fight(object me)
{
        command("say 在下哪里是您的对手？");
        return 0;
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting",0 , ob);
        }
}

void greeting(object ob)
{
        // 2026-04-30: unused variable commented out
        // object book;
        // 2026-04-30: unused variable commented out
        // object sword;
        if((int) ob->query("marks/murder") == 0)
        {
        if( (int) ob->query("marks/林平之") == 0 ) 
        say( "林平之说道：“这位"+ RANK_D->query_respect(ob) 
+"，可曾见过家父林镇南？” \n");
        else
        {
         ob->set("marks/林平之", 0);
         ob->set("potential", (int) ob->query("potential")+60+random(41));
	 call_out( "leave_stage", 1, this_player(), 0 );
       
        }
        }
        else
                call_out("killhim",1,ob);
}

void killhim(object ob)
{
        ob->set("marks/murder", 0);
        ob->set("marks/林平之", 0);
        set("title", RED"悲愤欲绝"NOR);
        
        command("chat 你．．你．．你们居然杀了我父亲，纳命来！\n");  

        set("chat_msg_combat", ({
"林平之悲愤欲绝的骂道：你．．你．．你们居然杀了我父亲，纳命来！",
                (: random_move :),
        }) );
        set("chat_chance", 15);
        set("chat_msg", ({
"林平之悲愤欲绝的骂道：你．．你．．你们居然杀了我父亲 ，纳命来！",
                (: random_move :),
        }) );
        set_temp("apply/force",4000);
        set_temp("apply/max_force", 2200);
        set_temp("apply/force_factor", 30);
        set_temp("apply/combat_exp", 1500000);
        set_temp("apply/damage", 250);
        carry_object(__DIR__"obj/sword")->wield();
        set_skill("pixie-sword", 120);
        map_skill("sword","pixie-sword");
	map_skill("parry","pixie-sword");
	map_skill("dodge","pixie-sword");
	command( "follow "+ob->query("id"));
        kill_ob(ob);
        ob->kill_ob(this_object());

}
 void leave_stage(object who, int stage)
{
        object obj,room,room1;
        tell_object(who, leave_msg[stage]);
        if( ++stage < sizeof(leave_msg) ) {
        call_out( "leave_stage", 2, who, stage );
        return;
     } 
        else 
	 room = load_object(__DIR__"guodao");
 	room->delete("exits/west");
 	destruct(this_object());
	
}
                     
