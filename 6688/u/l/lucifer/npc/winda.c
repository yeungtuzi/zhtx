#include <ansi.h>

inherit "/std/char/doomnpc";

void create()
{
        set_name("不知火舞", ({ "buzhi huowu","winda"}) );
        set("long",@LONG
她是近几年来武林中最具传奇色彩的一个人物。她家世凄惨，全家在正邪两派
的巨斗中蒙难，有幸被日月神教圣姑任盈盈带回教中抚养成人。成为孤儿的她
异常刚烈坚毅，从小便刻苦习武，不到二十岁时便已名满天下，成为日月神教
顶尖高手中的佼佼者，正派人士谈之色变。但不料东窗事发，东方不败囚禁了
任我行，取而代之成为日月神教教主，教中的精英不断遭到排挤和暗杀，不知
火舞被逼无奈，只好叛出日月神教，开始了浪迹江湖的生涯。机缘巧合中，遇
上了金轮寺的大喇嘛龙象，身世相同的彼此两情依依，终成伉俪，成就了武林
中的一段佳话。不久以后，她又做出了一件震惊武林的举动来，夫妻二人联络
诸派高手，毅然前往有去无归的“幽明山庄”，在接天楼里联手击败了传说中
武功接近于神的『魔师』庞斑和『覆雨剑』浪翻云，从而创造了新的武林神话。
LONG
         );

        set("title",HIM"凤舞九天翔"NOR);
        create_family("步玄派", 8, "八代弟子");
        set("gender", "女性");
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
        set("per",50);
        set("str",100);
        set("age",35);
        set("bln",100);
        set("int",100);


        set_skill("taiji-shengong", 300);
        set_skill("xuanming-shenzhang", 300);
        set_skill("move", 300);
        set_skill("mysterrier", 300);
        set_skill("stormdance", 300);
        set_skill("spring-blade", 300);
        set_skill("qiankun-danuoyi", 300);
        set_skill("blade", 300);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set_skill("strike",300);
        set_skill("force",300);
        set_skill("dugong",300);


        map_skill("force","taiji-shengong");
        map_skill("strike","xuanming-shenzhang");
        map_skill("parry","qiankun-danuoyi");
        map_skill("dodge","stormdance");
        map_skill("move","mysterrier");
        map_skill("blade","spring-blade");
        prepare_skill("strike", "xuanming-shenzhang");
        set("skill_mark/spring-blade",1);

        set_temp("apply/damage",500);
        set_temp("apply/attack",100);
        set_temp("apply/armor",800);
        set_temp("apply/armor_vs_force",800);


        set("chat_chance_combat",100);
        set("chat_msg_combat", ({
                (: perform_action,"move.hasten" :),
                (: perform_action,"dodge.ensnare" :)
        }) );

        set("auto_heal",1);
        setup();

        add_money("tenthousand-cash",1);
        carry_rnd_equip(6,6);  
        carry_object("/u/m/masterall/dragonblade")->wield();
 
}                          

void init()
{
        set("shen",-1*this_player()->query("shen")/10);
        return;
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


