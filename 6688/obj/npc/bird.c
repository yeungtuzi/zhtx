#include <ansi.h>
 
inherit NPC;

void create()
{       
         set_name("北冥大鹏", ({ "roc" }) );
        set("long",
 
"这是一种来自北冥大泽的大鸟，它挥动翅膀卷起的飓风可以把人吹跑。\n");
        
        set("race", "野兽");
        set("age", 200);
        
        set("str", 80);
        set("cor", 40);
        set("spi", 40);
        set("int", 20);
        
        set("limbs", ({ "头部", "身体", "翅膀", "尾巴" }) );
        set("verbs", ({ "bite", "claw", "poke" }) );

        set_temp("apply/attack", 80);
        set_temp("apply/damage", 40);
        set_temp("apply/dodge", 70);
        set_temp("apply/armor", 30);
 
     set("combat_exp",1000000);
        setup();
 
}
int heal_up()
{
{
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1; 
}
        
void leave()
{
        object owner;
        message("vision",
                HIY + name() +
"长鸣一声,掀起一阵狂风,消失得无影无踪.\n\n"NOR,
environment(),
                this_object() );
        if( objectp(owner = query("possessed")) )
        {
                owner->add_temp("inv",-1);                
        }
        destruct(this_object());
}
        
void invocation(object who)
{
        int i;
        object *enemy;
        message("vision",
                HIY
"一阵狂风骤然刮起,一只大鹏鸟飞了过来,仿佛一片乌云!\n\n"NOR,
                environment(), this_object() );
        enemy = who->query_enemy();
        i = sizeof(enemy); 
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) )
enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                }
        }
        set_leader(who);
        set("possessed",who);
        who->add_temp("inv",1);    
}
int chat()
{
        object owner;

        if( !is_fighting() || !objectp(owner=this_object()->query("possessed"))
                || !owner->is_fighting() || environment(this_object()) != environment(owner) )
        {
                                call_out("leave", 1);
        }
        return 1;
}

void die()
{
        call_out("leave",1);
}

void unconcious()
{
        die();
}

int defeated_enemy(object victim)
{
        object owner;
        if( objectp(owner = query("possessed")) )
        {
                owner->defeated_enemy(victim);
                COMBAT_D->winner_task(owner,victim);
        }
}                                          

int killed_enemy(object victim)
{
        object owner;
        if( objectp(owner = query("possessed")) )
        {
                COMBAT_D->killer_reward(owner,victim);
        }
} 


