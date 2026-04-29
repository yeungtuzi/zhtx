#include <ansi.h>

inherit "/std/char/doomnpc";

void create()
{
        set_name("方夜羽", ({ "fang yeyu","fang","yeyu"}) );
        set("long",@LONG
        他是一个文士装束，英秀俊美但却体格轩昂魁捂的年轻人，背后背着两把短
戟，原来这就是传说中庞斑的首徒——方夜羽，他乃当年威临天下蒙皇忽必烈的嫡系
子孙，而庞斑承乃师蒙赤行遗命，特别挑选方夜羽出来，加以培育，以冀他能重夺在
汉人手裹失去的江山。他办事得狠辣绝对在当世的任何一位黑道高手之上。
LONG
         );

        set("title",YEL"小魔师"NOR);
        set("max_gin", 4000);
        set("max_kee", 8000);                    
        set("max_sen", 4000);
        set("max_force",5000); 
        set("max_mana",4000);
        set("mana",4000);
        set("max_atman",2000);
        set("atman",4000);
        set("force",8000);
        set("force_factor",250);     
        set("combat_exp",59999999);
        set("cor",50);
        set("cps",50);   
        set("spi",50);
        set("per",30);
        set("str",120);
        set("age",35);
        set("bln",50);

        set_skill("taomo-dafa", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("unarmed",200);
        set_skill("force",200);
        set_skill("magic",200);
        set_skill("spells",200);
        set_skill("halberd",200);

        map_skill("force","taomo-dafa");
        map_skill("unarmed","taomo-dafa");
        map_skill("parry","taomo-dafa");
        map_skill("dodge","taomo-dafa");
        map_skill("magic","taomo-dafa");
        map_skill("spells","taomo-dafa");
        map_skill("halberd","taomo-dafa");
        prepare_skill("unarmed","taomo-dafa");

        set_temp("apply/damage",50);

/*
        set("chat_chance",3);
        set("chat_msg_combat", ({
                "浪翻云凝视着窗外的明月，姿态悠闲之极。\n",
                "浪翻云举起盛满了清溪流泉的酒壶喝了一大口，笑道：痛快，痛快！\n"
        }) );
*/
        set("chat_chance_combat",10);
        set("chat_msg_combat", ({
                (: exert_function,"swat" :),
                (: command,"conjure shade-sense" :),
        }) );

        set("auto_heal",1);
        setup();

        add_money("tenthousand-cash",1);
        carry_rnd_equip(4,5);   
        carry_object("/d/xanadu/npc/obj/ji")->wield();
}                          

int init()
{
        set("shen",-500000);
        return 1;
}
                             
int killed_enemy(object ob)
{
        command("heng");
}                 
                     
int chat()
{
        add("force",50);
        receive_curing("kee",50);
        receive_curing("sen",50);
        receive_curing("gin",50);
        ::chat();
}
void die()
{
        mapping victims;
        string *vic;
        int i;
        object player;

        victims = query_temp("beat");
        if( !mapp(victims) || !sizeof(victims) ) return ::die();
        vic = keys(victims);
        i = sizeof(vic);
        while(i--)
        {
                if( userp(player=find_player(vic[i])) && present(player,environment()) )
                {
                        tell_object(player,"你受到了奖励！你的武林声望提高了！\n");
                        player->add("wlshw",1+random(2));
                }
        }                       
        ::die();

}



