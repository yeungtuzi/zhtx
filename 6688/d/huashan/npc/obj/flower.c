#include <ansi.h>
#include <armor.h>
inherit HEAD;

string *name=({
	"[1;34m蓝天鹅[0m","[1;31m红玫瑰[0m","[1;37m香水百合[0m",
	"[1;31m雏菊[0m","[30m[46m黑郁金香[0m","[1;35m勿忘我[0m",
	"[1;32m含羞草[0m","[1;37;41m满天星[0m","[35m紫罗兰[0m",
	"[1;33m康乃馨[0m","[1;35m情人草[0m","[1;36m兰花[0m",
	"[1;32m君子兰[0m","[31m太阳花[0m","[1;37m白茶花[0m",
	"[1;33m黄玫瑰[0m",
});

void create()
{
	string flower_name=name[random(sizeof(name)-1)];
	set_name(flower_name,({"beautiful flower"}));
	        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "美丽的"+flower_name+"\n");
                set("unit", "朵");
                set("value", 200);
                set("material", "plant");
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
                set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n");
                set("female_only", 1);
        }
        setup();


}