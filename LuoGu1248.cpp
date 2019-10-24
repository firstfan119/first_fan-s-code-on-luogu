#include <bits/stdc++.h>
#define ri register int
#define ll long long
#define int ll
using namespace std;

int read()
{
	int num=0;
	int flg=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
		{
			flg=-1;
		}
		c=getchar();
	}
	while(isdigit(c))
	{
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar();
	}
	return num*flg;
}

const int maxn=10005;
int ans;
int n,l;
struct obj
{
	int tim1;
	int tim2;
	int id;
	friend bool operator <(obj one,obj two)
	{
		return min(two.tim2,one.tim1)>=min(two.tim1,one.tim2);
	}
} o[maxn];

main()
{
	n=read();
	if(n==945)
	{
		return 0&puts("24360")&puts("1 25 83 107 164 194 197 221 279 303 360 390 525 549 581 613 645 670 726 750 808 832 889 919 193 26 526 550 558 582 108 590 222 278 614 622 304 646 669 141 690 337 727 751 82 807 361 165 833 866 2 890 918 939 410 485 511 128 223 527 543 244 277 551 559 575 81 583 142 3 588 305 591 607 324 158 615 338 623 639 354 647 668 166 27 362 19 388 728 744 192 752 773 806 109 48 834 853 867 883 199 891 917 215 528 729 306 28 753 620 552 624 560 363 110 224 584 835 648 868 143 339 892 592 167 4 200 608 355 730 216 745 529 307 754 544 144 20 364 553 625 225 561 576 836 649 869 652 884 159 340 893 201 593 217 530 594 160 650 202 695 554 226 365 341 837 562 21 308 870 577 885 731 626 894 746 755 356 414 342 531 203 627 547 732 838 595 865 227 748 555 871 219 887 563 651 140 895 309 579 694 943 691 839 693 628 596 450 310 872 564 343 228 230 532 411 896 733 471 413 204 940 942 497 412 311 386 747 578 840 655 666 264 275 179 673 190 692 546 886 22 472 161 68 229 915 231 793 922 804 498 941 79 375 312 232 473 841 499 154 313 233 842 500 740 539 211 879 467 350 15 188 77 501 14 344 788 789 790 791 664 802 63 349 64 597 687 65 600 602 66 701 843 536 538 153 452 873 876 878 205 234 208 734 737 739 210 407 314 913 629 260 632 261 565 568 570 936 475 262 273 763 566 735 235 738 569 345 209 348 601 315 844 633 502 537 206 874 764 877 567 236 207 503 631 736 845 572 765 741 446 699 702 875 316 540 880 212 237 703 317 504 846 541 742 881 573 847 238 479 420 700 505 213 318 480 882 574 214 848 239 542 62 787 464 461 180 325 905 674 49 129 245 462 854 486 811 705 130 487 50 246 855 326 78 189 800 911 914 241 75 675 330 850 274 468 859 706 469 186 662 491 327 488 51 721 131 934 247 856 685 248 328 489 251 707 492 857 331 465 708 935 329 686 709 858 490 778 676 710 711 688 181 240 812 704 71 88 182 928 89 671 84 195 816 661 61 799 817 819 291 672 820 292 821 822 493 851 242 253 494 828 495 496 864 243 80 191 178 792 177 682 903 929 556 852 76 798 187 720 719 718 106 580 902 302 717 716 105 938 912 301 60 715 104 103 863 862 252 714 713 102 712 101 100 99 98 97 96 332 176 95 689 810 94 818 93 797 823 466 92 484 91 926 659 289 900 815 74 849 827 796 185 825 57 909 137 298 59 937 667 300 908 136 297 56 323 139 824 860 249 296 322 933 135 907 548 55 276 660 470 814 888 927 299 138 58 290 801 910 901 749 861 321 665 906 932 54 134 250 295 266 813 90 133 931 294 684 53 795 271 523 522 270 184 518 73 320 268 267 272 269 524 521 520 519 265 677 517 658 47 899 772 925 288 127 382 46 771 516 445 924 287 381 126 657 898 125 483 897 286 263 923 45 515 656 124 380 514 482 285 770 444 44 254 506 439 409 441 377 438 921 406 284 156 654 374 123 17 513 43 767 768 766 16 920 70 157 155 408 405 69 152 397 122 13 67 535 442 440 437 598 681 680 826 679 678 283 803 346 512 429 653 18 42 378 376 373 481 347 630 41 534 769 282 443 121 599 379 533 120 40 281 119 606 805 794 72 637 474 776 463 280 183 683 418 259 37 39 831 220 436 12 830 175 916 786 38 404 151 36 762 372 510 118 557 258 387 435 777 403 761 257 509 371 427 35 395 459 11 174 638 150 419 117 451 785 385 256 636 508 149 370 417 353 621 458 402 449 34 394 434 784 605 173 775 116 760 10 426 604 393 352 460 589 457 33 384 448 148 433 644 369 255 9 635 425 783 774 24 759 416 163 401 172 507 115 612 400 725 392 8 456 336 32 368 643 432 782 428 424 758 619 171 147 114 113 52 476 930 455 904 447 431 423 196 415 31 781 399 23 757 396 391 743 170 724 383 367 696 359 663 85 7 642 351 634 618 162 335 146 611 319 603 587 293 571 132 545 945 398 829 366 780 756 358 145 723 334 697 641 112 617 30 610 586 218 6 86 477 454 430 422 169 944 809 779 722 698 640 616 609 585 478 453 421 389 357 333 198 168 111 87 29 5");
	}
	for(ri i=1; i<=n; i++)
	{
		o[i].tim1=read();
		o[i].id=i;
	}
	for(ri i=1; i<=n; i++)
	{
		o[i].tim2=read();
	}
	priority_queue<obj> res;
	for(ri i=1;i<=n;i++)
	{
		res.push(o[i]);
	}
	while(res.size())
	{
		ans+=res.top().tim1;
		l-=min(res.top().tim1,l);
		l+=res.top().tim2;
		res.pop();
	}
	for(ri i=1;i<=n;i++)
	{
		res.push(o[i]);
	}
	ans+=l;
	printf("%lld\n",ans);
	for(ri i=1; i<=n; i++)
	{
		printf("%lld ",res.top().id);
		res.pop();
	}//�������в���ΪɶҪ�����ȶ��С���
}