/*luorenjie.c*/
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("罗人杰",( {"luo renjie","renjie","luo"}  ));
        set("gender", "男性" );
        set("age", 25);
        set("str", 28);
        set("cor", 25);
        set("cps", 25);
      
        set("max_force", 600);
        set("force", 900);
        set("force_factor", 50);
        set("attitude", "friendly");       
        set("long",@LONG
 他是余沧海的嫡传弟子,是青城派年轻一代的高手,乃是青城四秀老四.
余沧海派他来守卫摘剑池，足见他的功夫端是了得。
LONG);

       

        set("combat_exp", 400000);
        

        set("chat_chance_combat", 60);

        set_skill("unarmed", 80);
        set_skill("parry", 80);
        set_skill("dodge", 40);
        set_skill("sword", 60);
        set_skill("force", 40);

        set_skill("qingcheng-steps", 80);
        set_skill("cuixin-zhang",80);
        set_skill("pine-sword", 50);
        set_skill("qingcheng-force",40);
 
       create_family("青城派", 19, "弟子");

      map_skill("sword", "pine-sword");
      map_skill("dodge", "qingcheng-steps");
      map_skill("parry", "pine-sword");     
      map_skill("unarmed","cuixin-zhang");
      map_skill("force","qingcheng-force");
 
        setup();
        add_money("silver", 8);
        carry_object("/obj/cloth")->wear();
        
}
void init()
 {
            add_action("do_gogo","go");
            add_action("do_west","west");
 }

int do_gogo(string arg)
 {        object me;
          me=this_player();

if( (arg == "west")&&( me->query_temp("weapon") || me->query_temp("secondary_weapon") ) )
             {
            write(CYN "罗人杰彬彬有礼地说道:" + RANK_D->query_respect(me)+",请摘下兵器再进本观.\n"NOR);
           return 1;
        }
        return 0;
}      
int do_west()
{    object me;
     me=this_player();
      if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
            {   write(CYN "罗人杰彬彬有礼地说道:" + RANK_D->query_respect(me)+",请摘下兵器再进本观.\n"NOR);
                return 1;
             }
       return 0;
}
