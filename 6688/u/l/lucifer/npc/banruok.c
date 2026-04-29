#include <ansi.h>

inherit "/std/char/doomnpc";

void create()
{
        set_name("龙象", ({ "long xiang","banruok"}) );
        set("long",@LONG
他是纵横天下里一位不世出的英雄。他的身世和不知火舞一样凄惨，自幼沦为
孤儿，从小就在西藏拉萨城里的铁匠铺里当小学徒，依靠打铁为生。终日的辛
苦劳作并没有使他消沉，反而造就了他的一身神力。当金轮法王在中原争夺武
林盟主不成而溃败而归，门下弟子东逃西散的时候，在途中遇上了龙象破例收
他为徒传授之无上密宗心法——龙象般若功，以及其成名绝技五行轮和金刚不
坏功。天赋禀异的他真有似如鱼得水，靠着一身的硬功和掌中的五行金轮横行
天下。他名为金轮法王之徒，但实际上已是西藏喇嘛教的中流砥柱，中原武林
皆因为龙象大喇嘛而不敢轻视西藏。后在机缘巧合中与不知火舞结为伉俪，联
合天下诸派英雄扫平了幽明山庄和接天楼，从而获得了极高的武林威望，至此
之后，天下武功尽为其所取，为其所用，至其不惑之年时，已然尽悉天下武学
之精华，成为当时统领武林的中坚力量。
LONG
         );

        set("title",HIG"绝版菜鸟"NOR);
        create_family("步玄派", 8, "八代弟子");
        set("max_gin", 10000);
        set("max_kee", 10000);                    
        set("max_sen", 10000);
        set("max_force",10000); 
        set("max_mana",10000);
        set("mana",20000);
        set("max_atman",10000);
        set("atman",20000);
        set("force",20000);
        set("force_factor",350);     
        set("combat_exp",79999999);
        set("cor",100);
        set("cps",100);   
        set("spi",100);
        set("per",30);
        set("str",100);
        set("age",35);
        set("bln",100);
        set("int",100);

        set_skill("hunyuan-yiqi", 300);
        set_skill("qishang-quan", 300);
        set_skill("move", 300);
        set_skill("mysterrier", 300);
        set_skill("lingboweibu", 300);
        set_skill("dugu-jiujian", 300);
        set_skill("qiankun-danuoyi", 300);
        set_skill("sword", 300);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set_skill("cuff",300);
        set_skill("force",300);
        set_skill("dugong",300);


        map_skill("force","hunyuan-yiqi");
        map_skill("cuff","qishang-quan");
        map_skill("parry","qiankun-danuoyi");
        map_skill("dodge","lingboweibu");
        map_skill("move","mysterrier");
        map_skill("sword","dugu-jiujian");
        prepare_skill("cuff", "qishang-quan");

        set_temp("apply/damage",600);
        set_temp("apply/attack",100);
        set_temp("apply/armor",800);
        set_temp("apply/armor_vs_force",800);
        set_temp("pfm/shaolin_jzz", 1);


        set("chat_chance_combat",100);
        set("chat_msg_combat", ({
                (: perform_action,"move.hasten" :),
                (: perform_action,"po-throwing" :)
        }) );

        set("auto_heal",1);
        setup();

        add_money("tenthousand-cash",1);
        carry_rnd_equip(6,6);  
        carry_object("/d/qiankun/obj/jian2")->wield();
 
}                          

void init()
{
        set("shen",-1*this_player()->query("shen")/10);
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
                        player->add("wlshw",3);
                }
        }                       
        ::die();

}


