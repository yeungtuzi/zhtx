// dagger.c 42book奖励
#include <ansi.h>
#include "/ldg/std/adv_armor.h"

inherit ADV_CLOTH;

void create()
{
        set_name(HIW "真丝"+HIC"宝"+HIY"甲" NOR, ({ "bao jia", "jia" }) );
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这件宝甲就是当年韦小宝救驾时身着的，据说刀枪不入，是武林人士梦寐以求的护具，\n但又有几个人有韦小宝那么好的运气和福气呢？\n");
                set("value", 500);
                set("material", "steel");
                set("unpawnable",1);
                set("adv_props/add_max_kee",25);
                set("adv_props/armor",100);
                set("adv_props/armor_vs_force",200);
                set("wear_msg", HIG"$N「唰」的一声打开一件$n"+HIG"穿在身上，举手抬足竟没有感到一丝累赘。\n"NOR);

        }
        setup();
}
int wear()
{
       object me,ob;
       me = this_player();
       ob = this_object();

              if( !me->query("book42_finished"))
                return notify_fail("你从什么渠道搞到这件至宝的？还不赶紧向巫师汇报！隐瞒不报你的小命就不长了。\n");

        return ::wear();
}

