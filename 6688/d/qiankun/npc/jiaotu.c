// jiao_zhong1.c
//write by masterall
//
#include <ansi.h>
inherit NPC;
 
#include <random_name.h>
 
 
void kailiu();
 
void create()
{
         string name,id,nick;
 
        name = get_rndname();
        id = get_rndid();
        nick = get_rndnick();
        
         set_name(name, ({ id, "jiaotu" }) );
        set("gender", "男性");
         set("title",BLK "乾坤教" NOR + HIB "教徒");
         set("nickname", nick); 
 
        set("age", 20);
        set("long",
                "这家伙满脸横肉，一付凶神恶煞的模样，令人望而生畏。\n");
        set("combat_exp", 15000+random(15000));
         set("shen_type", -1);
        set("shen",-10000);
        set("attitude", "heroism");
        set("chat_chance_combat", 80);
         set("chat_msg_combat", ({
                (HIY "乾坤教天下无敌，一统江湖!\n" NOR),
                (HIG "武功盖世，英名神武圣教主万岁万万岁!\n" NOR),
         }) );
 
 
         set_skill("force", 80);
         set_skill("taohua-force", 80);
        set_skill("move", 80);
         set_skill("dodge", 80);
         set_skill("fall-steps", 80);
        set_skill("claw", 80);
         set_skill("parry", 80);
         set_skill("sword", 80);
         set_skill("fuliu-jian", 80);
          set_skill("fonxansword", 80);  
         set_skill("cuixin-zhang", 80);
         set_skill("unarmed", 80);
         set_skill("spicyclaw", 80);
         set_skill("literate", 80);
 
         map_skill("force", "taohua-force");
         map_skill("dodge", "fall-steps");
         map_skill("move", "fall-steps");
        map_skill("unarmed", "cuixin-zhang");
         map_skill("parry", "fonxansword");
         map_skill("sword", "fonxansword");
         map_skill("claw", "spicyclaw");

         prepare_skill("claw", "spicyclaw");
         prepare_skill("unarmed", "cuixin-zhang"); 
 
         create_family("乾坤教", 16, "教徒");
 
  
        setup();
     
        
 

        add_money("gold", 1);
        carry_object("/obj/cloth/cloth")->wear();
 }
 
 int accept_fight(object me)
 {
         command("say 好小子, 居然敢同我们乾坤教作对, 看招!");
         command("grin"); 
         kill_ob(me);
         return 1;
 }
 
 int accept_kill(object killer)
 {
        int i;
        object *ob,me;
        me=this_object();
        ob = all_inventory(environment(me));
         for(i=0; i<sizeof(ob); i++) {
                 if( !living(ob[i]) || ob[i]==me ) continue;
                 if( ob[i]->query("family/family_name")!="乾坤教") continue;
                if( ob[i]->query("id")==killer->query("id")) continue;
                 if( userp(ob[i]) ) ob[i]->kill_ob(killer);
                 else if( !ob[i]->is_killing(killer) ) ob[i]->kill_ob(killer);
                write(ob[i]->query("name")+ "吼道:"+HIY 
                 "好小子, 居然敢杀我们乾坤教的人,死去吧你!\n" NOR);
         }
         return 1;
 }

