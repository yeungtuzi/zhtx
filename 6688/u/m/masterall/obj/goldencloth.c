//goldencloth.c
//by masterall

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        int i;
        i = 100 + random(100);
        set_name(HIY"金缕"+HIG"玉"+HIC"衣"NOR, ({ "golden cloth", "cloth" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                        HIY"这件金缕玉衣是由金蚕丝线混合千年老藤编织而成，然后配以上乘玉器做为装饰，表面上虽是华丽，\n"
                        "但其价值已经远远的超越了一件普通的宝物，被千百年来的武林人士视为护具之中的神品。\n"NOR);
                set("unit", "件");
                set("no_drop","这件宝贝这么珍贵你怎么舍得扔了卖了？也不能给别人。");
                set("no_get","你看着这件稀世珍品，又不敢去拿，生怕招来杀身之祸。");
                set("no_put","你想把这件宝贝放哪里去？不怕给弄脏了？");
                set("no_sell","这东西也敢卖？就算你想卖人家未必敢买！");
                set("unpawnable",1);
                set("value", 10000);
                set("material", "gold");
                set("armor_prop/armor", i);
                set("armor_prop/armor_vs_force", i);
                set("armor_prop/attack", i/10);
                set("armor_prop/personality", 15);
                set("been_hit", 0);
                set("wear_msg", HIC "只听「哗」的一声，$N展开一件晶莹剔透的"+HIY"金缕"+HIG"玉"+HIC"衣"+HIC"穿在身上。
瞬时间天地变色，日月失辉，寰宇中的千万生灵都为这至高无上的神物所折服了。\n" NOR);

        }
        setup();
}

int wear()
{
       object me,ob;
       me = this_player();
       ob = this_object();
        if( this_player()->query_skill("force",1) < 300)
        {
                return notify_fail("你的内功心法等级太低了，穿不上这件武林至宝。\n");
        }
        if( this_player()->query("wlshw") < 100 )
        {
                return notify_fail("你在江湖中的声望太低了，别人还以为这东西是你从哪里抢来的呢！\n");
        }
        if( this_player()->query("combat_exp") < 8000000)
        {
                return notify_fail("你江湖经验太低了，还穿不了这件武林至宝。\n");
        }
        return ::wear();
}


int dispersion_damage(object killer,object victim,int damage)
{
        object ob = this_object();
        int foo,foo2;
        foo = victim->query_skill("force",1);
        foo -= victim->query_skill("taiji-shengong",1);
        foo -= victim->query_skill("hunyuan-yiqi",1);
        if ( foo < 1 ) foo = 1;
        if ( foo > 400 ) foo = 400;
   //     foo2 = damage * foo * foo /200000 ;
        damage = damage * foo * foo /180000 ;

//killer很明显是动手打人的
//victim是被打的，
//damage是将要给的伤害值。


        message_vision(HIG"$n眼见形势大急，慌乱间不知所措，但却见身上"+ob->query("name")+HIG"一道青光升起，\n护住了$n的周身要穴，$N则被眼前的神迹惊得目瞪口呆！！\n"NOR,killer,victim);  
        add("been_hit", 1);
        if((int)query("been_hit")>=35) {
                tell_object(victim,HIW"\n\n你的金缕玉衣被打破了，看着这件千辛万苦得来但此时却破破烂烂的衣服，\n你几乎心疼得眼珠子都掉了下来，但仍旧咬了咬牙，把它丢掉了！\n\n"NOR);
                call_out("destruct_me", 1, this_object());

        }

        return damage ;
}

void destruct_me(object me)
{
        destruct(me);
} 


