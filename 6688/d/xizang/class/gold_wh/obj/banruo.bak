// /d/xizang/class/gold_wh/obj/banruo.c

inherit ITEM;

void create()
{
      set_name("龙象般若功",({"long xiang ban ruo gong", "book", "gong"}));
      set_weight(100);
      if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", @TEXT
龙象般若功是密宗最强也是最难练的内功,据说练成之后可有十龙十象之力,但是
金轮法王自己也没有完全练成,他的两个亲传弟子桑吉多与达尔巴都是蛮勇之人,
根本无法入门.传说中只有藏边最伟大的英雄格萨尔完全练成此功,但他失踪已经
很多年了,有人说他已升天成佛.
TEXT
);
                set("value", 0);
                set("material", "paper");
                set("skill", ([
                        "name": "banruo",
                "exp_required": 100000,
                    "sen_cost": 100,
                  "difficulty": 100,
                   "max_skill": 999,
                ]) );
        }
}
