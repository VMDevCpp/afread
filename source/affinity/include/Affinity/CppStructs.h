// Copyright (c) 2020-2021 Vladimir Mamonov
// Licensed under the MIT license.

#ifndef AFFINITY_CPPSTRUCTS_H
#define AFFINITY_CPPSTRUCTS_H

/* This file is auto generated                               */
/* Do not edit it manually                                   */

#include "Affinity/Model.h"
#include "Affinity/Utils.h"

#include <array>
#include <string>
#include <vector>

namespace AffinityReader::CppModel {

template <class T>
using vector = std::vector<T>;
using string = std::string;
template <class T, std::size_t N>
using array = std::array<T, N>;

struct BaseAtt;        // IWYU pragma: keep
struct BaseLayer;      // IWYU pragma: keep
struct BaseAdjustment; // IWYU pragma: keep
struct BaseFill;       // IWYU pragma: keep
struct BaseBitm;       // IWYU pragma: keep
struct BaseEffect;     // IWYU pragma: keep
struct BaseFlDS;       // IWYU pragma: keep
struct BaseShape;      // IWYU pragma: keep
struct BaseFrms;       // IWYU pragma: keep
struct BaseColor;      // IWYU pragma: keep
struct BaseBrush;      // IWYU pragma: keep
struct BaseExport;     // IWYU pragma: keep
struct BaseCmd;        // IWYU pragma: keep
struct BGrd;
struct BlnR;
struct BrDy;
struct CnMP;
struct CoDe;
struct CrpP;
struct CrvD;
struct DFFO;
struct DMdf;
struct DcHI;
struct DocS;
struct DyBm;
struct ExBF;
struct FDsc;
struct FTXR;
struct FilS;
struct ForC;
struct Futr;
struct GAtt;
struct GStr;
struct GlAS;
struct GrMP;
struct GraP;
struct Grup;
struct HSLA;
struct ICC;
struct ICCP;
struct ILDO;
struct ILGI;
struct ILSN;
struct ILTI;
struct LDsc;
struct LR3D;
struct LStr;
struct LSty;
struct Layt;
struct LigS;
struct Matx;
struct ObjS;
struct OpAV;
struct PAtt;
struct PBxR;
struct PCrv;
struct PCvD;
struct PLig;
struct PSRe;
struct PTCf;
struct PTEq;
struct PTNd;
struct PaAS;
struct PcRs;
struct Per_42;
struct PfPr;
struct PthT;
struct Quad;
struct RBMI;
struct RGBA;
struct Rec;
struct Rstr;
struct SCRn;
struct SNAR;
struct SPst;
struct SRst;
struct SSAS;
struct Scal;
struct Sctn;
struct Sele;
struct ShpN;
struct Slic;
struct SnpG;
struct SpRV;
struct SpRe;
struct Spln;
struct Sprd;
struct Stop;
struct Stry;
struct TBFR;
struct TBSO;
struct TStS;
struct TSty;
struct TbFt;
struct TexS;
struct TxFU;
struct TxFl;
struct TxtA;
struct UVCn;
struct UnSR;
struct UndR;
struct VwPD;
struct v_CB1;
struct v_CB2;
struct v_CB3;
struct v_CB4;
struct v_CB5;
struct v_C1;
struct v_C2;
struct ascp;
struct bres;
struct cibs;
struct enty;
struct erev;
struct pack;
struct pdsi;
struct pmda;
struct temp;

#pragma pack(push, 1)

struct BaseDels
{
	enum class Type
	{
		Unknown,
		AuFD,
		DrpD,
		FSDe,
		GADD,
		GAID,
		GAOD,
		GASD,
		OTFD,
		PADD,
		PADS,
		PAID,
		PAOD,
		SLAD,
	};
	Type base_type = Type::Unknown;

	/* AFAt*, DrCp* */
	BaseAtt* Att;
	int32_t  Fild;
	int32_t  Key_; /* NOLINT(readability-identifier-naming) */
};

struct BaseLayer
{
	enum class Type
	{
		Unknown,
		v_3DLA, /* NOLINT(readability-identifier-naming) */
		BCRA,
		BWRA,
		CBRA,
		CMRA,
		CPTx,
		CnsN,
		Comp,
		CrRA,
		EmbN,
		ExRA,
		FRst,
		FlRN,
		GrRA,
		Grup,
		HsRA,
		ImgN,
		InRA,
		LeRA,
		MPIN,
		MRst,
		OCRN,
		ObjS,
		PCrv,
		PfRA,
		PoRA,
		RcRA,
		Rstr,
		SCRA,
		SHRA,
		SNEN,
		SNRR,
		SPRA,
		ScPr,
		Scop,
		ShRN,
		ShpN,
		SlcP,
		Slic,
		SpTA,
		Sprd,
		StkN,
		ThRA,
		TxtA,
		TxtF,
		TxtS,
		TxtT,
		VbRA,
		WBRA,
	};
	Type base_type = Type::Unknown;

	bool ABEn;
	/* v_3DLA*, BCRA*, BWRA*, CBRA*, CMRA*, CrRA*, FlRN*, GrRA*, Grup*, HsRA*, InRA*, LeRA*, MRst*, OCRN*, PCrv*, PfRA*, PoRA*, RcRA*,
	 * Rstr*, SCRA*, SHRA*, SPRA*, ShpN*, SpTA*, ThRA*, VbRA*, WBRA* */
	vector<BaseLayer*> AdCh;
	/* v_3DLP*, BCP_38*, BWP_38*, CIPP*, CnMP*, CoBP*, CrvP*, ExpP*, GrMP*, HSSP*, LeFP*, LevP*, PosP*, RecP*, SCoP*, SHiP*, STPa*, SoPP*,
	 * ThrP*, VibP*, WhBP* */
	BaseAdjustment* AdjP;
	void*           AncD;
	EnumT           Anch;
	uint32_t        BFCr;
	vector<FDsc*>   BFFl;
	/* FDsc*, FilS* */
	BaseFill* BFil;
	/* PCrv*, ShpN*, TxtF* */
	BaseLayer* BGMs;
	int32_t    BitI[4];
	int32_t    BitR[4];
	/* DyBm*, EmbR* */
	BaseBitm* Bitm;
	/* Comp*, Grup*, MRst*, PCrv*, Rstr*, Scop*, ShpN*, TxtA*, TxtF* */
	BaseLayer*        BlMM;
	BlnR*             BlRa;
	EnumT             Blnd;
	bool              CEdb;
	vector<curve16_t> CGds;
	EnumT             CLiT;
	int32_t           CMsk;
	/* v_3DLA*, BCRA*, BWRA*, CBRA*, CMRA*, CPTx*, CnsN*, Comp*, CrRA*, EmbN*, ExRA*, FRst*, FlRN*, Grup*, HsRA*, ImgN*, LeRA*, MPIN*,
	 * MRst*, PCrv*, PfRA*, RcRA*, Rstr*, SCRA*, SHRA*, SNEN*, SNRR*, Scop*, ShRN*, ShpN*, StkN*, TxtA*, TxtF*, TxtS*, TxtT*, VbRA*, WBRA*
	 */
	vector<BaseLayer*> Chld;
	bool               ClrF;
	bool               CnCl;
	int32_t            CnCp;
	int32_t            CnFm;
	int32_t            CnJn;
	double             CnML;
	double             CnOf;
	EnumT              ComO;
	PCvD*              Crvs;
	uint32_t           Ctrl;
	EnumT              CvWi;
	double             CvsB[4];
	ILDO*              DLnk;
	void*              Data;
	string             DefD;
	string             Desc;
	string             DfId;
	vector<EnumT>      DrwO;
	/* Grup*, MRst*, PCrv*, Rstr*, Scop*, ShpN*, TxtF* */
	BaseLayer* DsMa;
	/* Grup*, MRst*, PCrv*, Rstr*, Scop*, ShpN*, TxtF* */
	BaseLayer* EdMa;
	bool       Edtb;
	string     ExFn;
	bool       ExIn;
	bool       ExtE;
	double     FOV;
	float      FOpc;
	double     FTxS[6];
	EnumT      FTyp;
	/* Comp*, Grup*, MRst*, PCrv*, Rstr*, Scop*, ShpN*, TxtA*, TxtF* */
	BaseLayer* FiEM;
	/* BevE*, ColO*, Gaus*, GrdO*, InnG*, InnS*, OutG*, PhgB*, Shad*, Strk* */
	vector<BaseEffect*> FiEf;
	TxFl*               Flow;
	uint64_t            Flsz;
	vector<string>      Frst;
	ILGI*               GLnk;
	bool                GdsA;
	vector<double>      GdsH;
	vector<double>      GdsV;
	string              GooI;
	/* Grup*, MRst*, PCrv*, Rstr*, Scop*, ShpN*, TxtF* */
	BaseLayer* HKMs;
	bool       HsFC;
	EnumT      HyTr;
	string     Hypr;
	EnumT      Hyty;
	EnumT      IPlc;
	/* v_00DS*, FlDS* */
	BaseFlDS*     IRDS;
	bool          IgBG;
	bool          IgTW;
	bool          IsVF;
	uint32_t      LICr;
	vector<FDsc*> LIFl;
	vector<LDsc*> LILn;
	LDsc*         LSty;
	double        Lati;
	double        Long;
	bool          MEtb;
	/* MRst*, Rstr* */
	BaseLayer*               MRaM;
	int64_t                  MfTm;
	string                   MiID;
	vector<array<double, 4>> MrgA;
	vector<void*>            MrgF;
	double                   OCRc[4];
	int32_t                  ODPI;
	float                    Opac;
	BGrd*                    Opts;
	/* PCrv*, ShpN* */
	BaseLayer* PFMs;
	/* FDsc*, FilS* */
	BaseFill*      PFil;
	bool           PasT;
	PthT*          Path;
	EnumT          ProT;
	Per_42*        Psp_42;
	Quad*          Pspv;
	PthT*          RPth;
	double         Roll;
	SnpG*          SGrd;
	ILSN*          SLnk;
	vector<string> Scnd;
	double         ShpB[4];
	/* ShCR*, ShCg*, ShCl*, ShCr*, ShDA*, ShDS*, ShHt*, ShNR*, ShPi*, ShPy*, ShRR*, ShSS*, ShSg*, ShSt*, ShTr*, ShTz*, ShpD*, ShpE*, ShpT*
	 */
	BaseShape* Shpe;
	EnumT      Spac;
	double     SrBx[4];
	double     SrPB[4];
	double     SrPT[6];
	double     SrTr[6];
	/* TxtA*, TxtF* */
	BaseLayer* StMa;
	Stry*      StSt;
	ILTI*      TLnk;
	/* Grup*, MRst*, PCrv*, Rstr*, Scop*, ShpN*, TxtF* */
	BaseLayer* TMas;
	double     TWBo[4];
	/* CnsN*, Comp*, Grup*, MRst*, PCrv*, Rstr*, Scop*, ShpN*, TxtA*, TxtF* */
	BaseLayer* TWMa;
	EnumT      TWSt;
	RGBA*      TagC;
	EnumT      TrAn;
	int32_t    TrCn;
	double     TrFP[2];
	bool       TrFV;
	int32_t    TraC;
	/* FDsc*, FilS* */
	BaseFill* Trns;
	/* TxtA*, TxtF* */
	BaseLayer* TxFM;
	/* ArFr*, CoFr*, PaFr*, TbFr* */
	BaseFrms*    TxtH;
	Layt*        TxtL;
	vector<bool> UCGA;
	vector<bool> UMgA;
	bool         USnG;
	vector<bool> UmgF;
	void*        Unpr;
	/* Comp*, Grup*, PCrv*, Scop*, ShpN*, TxtF* */
	BaseLayer* VBFM;
	/* Comp*, Grup*, PCrv*, Scop*, ShpN*, TxtF* */
	BaseLayer* VLSM;
	/* Comp*, Grup*, PCrv*, Scop*, ShpN*, TxtF* */
	BaseLayer* VTrM;
	/* Comp*, Grup*, MRst*, PCrv*, Rstr*, Scop*, ShpN*, TxtA*, TxtF* */
	BaseLayer*   VisM;
	bool         Visi;
	Matx*        WRot;
	struct XCfg* XCfg;
	double       Xfrm[6];
	uint32_t     avin;
	PBxR*        bbxs;
};

struct BaseEffect
{
	enum class Type
	{
		Unknown,
		BevE,
		ColO,
		Gaus,
		GrdO,
		InnG,
		InnS,
		OutG,
		PhgB,
		Shad,
		Strk,
	};
	Type base_type = Type::Unknown;

	double Angl;
	EnumT  BlnM;
	/* CMYK*, HSLA*, LABA*, RGBA* */
	BaseColor* Colr;
	double     Comp;
	double     Dept;
	bool       Disr;
	bool       Enab;
	FDsc*      GrFl;
	double     Offs;
	double     Opac;
	Spln*      Prof;
	double     Radi;
	bool       SclO;
	double     Sftn;
};

struct BaseGlys
{
	enum class Type
	{
		Unknown,
		BrGl,
		FlrG,
		LLGl,
		PgNG,
	};
	Type base_type = Type::Unknown;
};

struct BaseColor
{
	enum class Type
	{
		Unknown,
		CMYK,
		GRAY,
		HSLA,
		LABA,
		Pant,
		RGBA,
		RegC,
	};
	Type base_type = Type::Unknown;

	string v_glb;
	double v_nse;
	double v_tnt;
};

struct BaseShape
{
	enum class Type
	{
		Unknown,
		ShCE,
		ShCR,
		ShCg,
		ShCl,
		ShCr,
		ShDA,
		ShDS,
		ShHt,
		ShNR,
		ShPi,
		ShPy,
		ShRR,
		ShSS,
		ShSg,
		ShSt,
		ShTr,
		ShTz,
		ShpD,
		ShpE,
		ShpT,
	};
	Type base_type = Type::Unknown;

	bool     AbSz;
	float    Curv;
	float    IRad;
	float    IRae;
	bool     Lock;
	uint16_t Pnts;
	float    Pos;
	float    ShCR[4];
	uint16_t Side;
	float    TlEP;
	float    TlHg;
};

struct BaseProp
{
	enum class Type
	{
		Unknown,
		ACrt,
		AbMp,
		Adjs,
		AstP,
		Brus,
		CrPP,
		DPOp,
		Filp,
		MacP,
		OSty,
		PTCP,
		PfPr,
		SGrP,
		SPPp,
		TExM,
		TonP,
	};
	Type base_type = Type::Unknown;
};

struct BaseFrms
{
	enum class Type
	{
		Unknown,
		ArFr,
		CoFr,
		PaFr,
		TbFr,
	};
	Type base_type = Type::Unknown;

	double FrmB[4];
};

struct BaseAdjustment
{
	enum class Type
	{
		Unknown,
		v_3DLP, /* NOLINT(readability-identifier-naming) */
		BCP_38, /* NOLINT(readability-identifier-naming) */
		BWP_38, /* NOLINT(readability-identifier-naming) */
		CIPP,
		CnMP,
		CoBP,
		CrvP,
		EDfP,
		ExpP,
		GrMP,
		HSSP,
		LeFP,
		LevP,
		PosP,
		RecP,
		SCoP,
		SHiP,
		STPa,
		SoPP,
		ThrP,
		VibP,
		WhBP,
	};
	Type base_type = Type::Unknown;

	float         Gamm;
	uint16_t      Vers;
	int32_t       Vibr;
	vector<float> Weig;
};

struct BaseFill
{
	enum class Type
	{
		Unknown,
		FDsc,
		FilB,
		FilG,
		FilN,
		FilS,
		HlkA,
		LDsc,
		OpAA,
		OtAt,
	};
	Type base_type = Type::Unknown;
};

struct BaseBrush
{
	enum class Type
	{
		Unknown,
		BmRB,
		IBRB,
		RRBr,
		SRBr,
	};
	Type base_type = Type::Unknown;

	BrDy*          Accn;
	BrDy*          Angl;
	string         BUid;
	EnumT          BlMo;
	EnumT          CnrS;
	BrDy*          Flow;
	vector<string> Frst;
	BrDy*          Hard;
	double         Head;
	BrDy*          HueS;
	BrDy*          LumS;
	EnumT          MkTM;
	double         MkTS;
	DyBm*          MskT;
	float          Opac;
	bool           RptB;
	bool           SABM;
	bool           SATI;
	bool           SAWE;
	EnumT          SMod;
	EnumT          SSMd;
	bool           SSSp;
	bool           SSSz;
	BrDy*          SatS;
	BrDy*          ScaX;
	BrDy*          ScaY;
	vector<string> Scnd;
	BrDy*          Shap;
	BrDy*          Size;
	float          Spac;
	bool           Strk;
	/* IBRB*, RRBr* */
	vector<BaseBrush*> SubB;
	double             Tail;
	BrDy*              TipC;
	vector<DyBm*>      TipT;
	int32_t            ToID;
	Spln*              WeES;
	bool               WetE;
};

struct BaseExCsts
{
	enum class Type
	{
		Unknown,
		ExCI,
		ExCt,
	};
	Type base_type = Type::Unknown;

	string cnst;
	string desc;
	EnumT  type;
};

struct BaseCmd
{
	enum class Type
	{
		Unknown,
		AAAC,
		AAMC,
		AARC,
		ACCm,
		AESC,
		AOSC,
		ARCm,
		ARFC,
		AROm,
		BCoA,
		BMCO,
		BMGO,
		BWAA,
		CASC,
		CBaA,
		CMTC,
		CRGl,
		ChMA,
		Clar,
		ClrX,
		Clrt,
		CmCm,
		CoCO,
		CrSl,
		CurA,
		DCCm,
		DNCm,
		DPro,
		Dupl,
		EnBE,
		EnCO,
		EnGA,
		EnGO,
		EnIS,
		EnIg,
		EnOg,
		EnPB,
		EnSh,
		EnSt,
		ExIn,
		ExpA,
		FAFH,
		FFCm,
		FTFH,
		FmTC,
		ForC,
		GOFl,
		GOTr,
		GrMA,
		GrNC,
		HslA,
		InGl,
		LevA,
		MC2C,
		MgDC,
		MvNC,
		OpCO,
		OpGO,
		PNoC,
		PRNS,
		RANC,
		RDF2,
		RDGC,
		RDNC,
		RDf2,
		REqT,
		RGBC,
		RHPC,
		RLbC,
		RLdC,
		RLig,
		ROCm,
		RRFC,
		RUSC,
		RVgC,
		SBMC,
		SCCM,
		SCER,
		SDDC,
		SDeC,
		SF2C,
		SGOC,
		SHAA,
		SLsC,
		SOBE,
		SOCO,
		SOGA,
		SOGO,
		SOIS,
		SOIg,
		SOOg,
		SOPB,
		SOSh,
		SOSt,
		SRlC,
		SSFH,
		SSLF,
		SSNS,
		SSaC,
		STAA,
		SViC,
		SecA,
		SetE,
		SflP,
		TrCm,
		TrSl,
		UANC,
		VibA,
		WBaA,
		XMgC,
		XStC,
	};
	Type base_type = Type::Unknown;

	bool    AARp;
	bool    AAtC;
	bool    ANme;
	bool    AThm;
	bool    AbrP;
	bool    AcWP;
	bool    AdSC;
	bool    AndS;
	bool    AppD;
	bool    ArtC;
	bool    Assi;
	EnumT   BlnM;
	bool    CArC;
	void*   CGlA;
	EnumT   CLis;
	bool    CMSl;
	bool    CSDf;
	bool    ClrS;
	bool    CopT;
	bool    Crct;
	int32_t DIdx;
	int32_t DefM;
	/* Grup*, Rstr*, Scop*, ShpN* */
	BaseLayer* Dest;
	bool       DidD;
	EnumT      Dire;
	bool       Done;
	bool       EnID;
	bool       Enab;
	/* EOEp*, EOGf*, EOHD*, EOJp*, EOPS*, EOPd*, EOPn*, EOSv*, EOTf*, EOTg*, EOXR* */
	BaseExport*   ExOp;
	double        Expo;
	int32_t       FMsk;
	vector<void*> Fak1;
	vector<void*> Fak2;
	uint32_t      FilI;
	/* FilG*, FilS* */
	BaseFill* Fill;
	/* Grup*, Scop*, Sprd* */
	vector<BaseLayer*> Fir1;
	vector<void*>      Fir2;
	vector<void*>      Fir3;
	/* Grup*, Scop*, Sprd* */
	vector<BaseLayer*> Fir4;
	vector<void*>      Fir5;
	/* Grup*, Scop*, Sprd* */
	vector<BaseLayer*> Fir6;
	/* Grup*, Scop*, Sprd* */
	vector<BaseLayer*> Fir7;
	vector<void*>      Fir8;
	vector<void*>      Fir9;
	/* Grup*, Scop* */
	vector<BaseLayer*> Fr10;
	/* Grup*, Scop* */
	vector<BaseLayer*> Fr11;
	/* Grup*, Scop* */
	vector<BaseLayer*> Fr12;
	/* Grup*, Scop*, Sprd* */
	vector<BaseLayer*> Fr13;
	/* Grup*, Scop*, ShpN*, Sprd* */
	vector<BaseLayer*> Fr14;
	/* Grup*, Scop*, Sprd* */
	vector<BaseLayer*> Fr15;
	vector<void*>      Fr16;
	vector<void*>      Fr17;
	vector<void*>      Fr18;
	/* Grup*, Scop*, Sprd* */
	vector<BaseLayer*> Fr19;
	/* Grup*, Scop*, Sprd* */
	vector<BaseLayer*> Fr21;
	/* Grup*, Scop*, Sprd* */
	vector<BaseLayer*> Fr22;
	vector<void*>      Fr23;
	/* Grup*, Scop*, Sprd* */
	vector<BaseLayer*> Fr24;
	vector<void*>      Fr25;
	vector<Sprd*>      Fr26;
	vector<void*>      Fr27;
	vector<void*>      Fr28;
	int32_t            FrcC;
	GStr*              Glyp;
	bool               GnHT;
	bool               IINS;
	SpRV*              IRec;
	double             InRc[4];
	/* CASC*, CmCm* */
	BaseCmd* Innr;
	EnumT    InsM;
	/* Grup*, PCrv*, Rstr*, Scop*, ShpN*, Sprd*, TxtA*, WBRA* */
	BaseLayer* InsT;
	double     Inte;
	double     InvR[4];
	LStr*      LDsc;
	/* Scop*, ShpN*, Sprd* */
	BaseLayer*           Layr;
	bool                 Live;
	bool                 MdTc;
	EnumT                Mode;
	bool                 Mono;
	void*                NDef;
	EnumT                NInM;
	vector<void*>        NewB;
	vector<GlAS*>        NewG;
	vector<struct LDsc*> NewL;
	struct Sele*         NewS;
	bool                 NoIn;
	/* v_3DLA*, BCRA*, BWRA*, CBRA*, CMRA*, CrRA*, ExRA*, GrRA*, HsRA*, ImgN*, InRA*, LeRA*, MRst*, OCRN*, PCrv*, PfRA*, PoRA*, RcRA*,
	 * Rstr*, SCRA*, SHRA*, SPRA*, Scop*, ShpN*, SpTA*, ThRA*, TxtA*, VbRA*, WBRA* */
	vector<BaseLayer*> NodA;
	/* v_3DLA*, BCRA*, BWRA*, CBRA*, CMRA*, CrRA*, ExRA*, FlRN*, GrRA*, HsRA*, InRA*, LeRA*, MRst*, OCRN*, PfRA*, PoRA*, RcRA*, SCRA*,
	 * SHRA*, SPRA*, SpTA*, ThRA*, VbRA*, WBRA* */
	BaseLayer*    Node;
	vector<void*> NwBm;
	void*         NwCm;
	UnSR*         NwTR;
	vector<void*> NwTV;
	void*         ODef;
	vector<GAtt*> OGAV;
	EnumT         OInM;
	vector<PAtt*> OPAV;
	vector<PAtt*> OPBV;
	struct Sele*  OSCo;
	GAtt*         OTGA;
	/* ACCm*, ARFC*, ExIn*, PNoC*, PRNS*, RRFC*, SCER*, SF2C*, SOBE*, SOCO*, SOGA*, SOGO*, SOIS*, SOIg*, SOOg*, SOPB*, SOSh*, SOSt*, SSFH*,
	 * SSLF*, SSNS* */
	vector<BaseCmd*> Objs;
	vector<void*>    OdTV;
	vector<void*>    OlCm;
	vector<bool>     OlE2;
	vector<GlAS*>    OlGA;
	vector<PaAS*>    OlPA;
	/* Grup*, PCrv*, Rstr*, ShpN* */
	vector<BaseLayer*>   OlPS;
	void*                OlSp;
	UnSR*                OlTR;
	vector<bool>         OldE;
	vector<GlAS*>        OldG;
	vector<struct LDsc*> OldL;
	/* Grup*, ObjS*, Rstr*, Scop*, ShpN* */
	vector<BaseLayer*>       OldN;
	vector<double>           OldO;
	vector<array<double, 6>> OldT;
	bool                     Opaq;
	double                   Orig[2];
	float                    PMax;
	float                    PMin;
	/* BCP_38*, BWP_38*, CnMP*, CoBP*, CrvP*, EDfP*, ExpP*, GrMP*, HSSP*, LevP*, SCoP*, SHiP*, STPa*, VibP*, WhBP* */
	BaseAdjustment*      Para;
	void*                Pres;
	bool                 Prev;
	bool                 Prog;
	GAtt*                RGA0;
	GAtt*                RGA1;
	PAtt*                RPA0;
	PAtt*                RPA1;
	vector<void*>        RSw2;
	double               Radi;
	bool                 RasS;
	vector<DyBm*>        RedT;
	FDsc*                SFDe;
	vector<PSRe*>        Sc10;
	vector<PSRe*>        Sc11;
	vector<PSRe*>        Sc12;
	vector<PSRe*>        Sc13;
	vector<PSRe*>        Sc14;
	vector<PSRe*>        Sc15;
	vector<void*>        Sc16;
	vector<void*>        Sc17;
	vector<void*>        Sc18;
	vector<PSRe*>        Sc19;
	vector<PSRe*>        Sc21;
	vector<PSRe*>        Sc22;
	vector<void*>        Sc23;
	vector<PSRe*>        Sc24;
	vector<void*>        Sc25;
	vector<PSRe*>        Sc26;
	vector<void*>        Sc27;
	vector<void*>        Sc28;
	EnumT                SeNT;
	vector<PSRe*>        Sec1;
	vector<void*>        Sec2;
	vector<void*>        Sec3;
	vector<PSRe*>        Sec4;
	vector<void*>        Sec5;
	vector<PSRe*>        Sec6;
	vector<PSRe*>        Sec7;
	vector<void*>        Sec8;
	vector<void*>        Sec9;
	struct Sele*         Sele;
	void*                Sour;
	void*                SrUC;
	bool                 Stac;
	bool                 TTTa;
	bool                 TocC;
	double               Tole;
	TxFU*                TxFl;
	bool                 UBLS;
	vector<void*>        USw2;
	vector<struct UndR*> UndR;
	bool                 UsFl;
	bool                 UsRS;
	bool                 UsTS;
	bool                 Vali;
	bool                 VsCh;
	bool                 VsRs;
	bool                 Work;
	double               Xfrm[6];
	bool                 eTSl;
	vector<void*>        lnkd;
	/* v_3DLA*, BCRA*, BWRA*, CBRA*, CMRA*, CrRA*, ExRA*, GrRA*, Grup*, HsRA*, ImgN*, InRA*, LeRA*, MRst*, OCRN*, PCrv*, PfRA*, PoRA*,
	 * RcRA*, Rstr*, SCRA*, SHRA*, SPRA*, ScPr*, Scop*, ShpN*, SpTA*, ThRA*, TxtA*, VbRA*, WBRA* */
	vector<BaseLayer*> mapo;
	bool               uTSl;
	/* CMRA*, GrRA*, Grup*, ImgN*, PCrv*, Rstr*, Scop*, ShpN*, TxtA* */
	vector<BaseLayer*> ulkd;
	vector<double>     uscl;
	vector<uint32_t>   usof;
};

struct BaseBitm
{
	enum class Type
	{
		Unknown,
		DyBm,
		EmbR,
	};
	Type base_type = Type::Unknown;
};

struct BaseAtt
{
	enum class Type
	{
		Unknown,
		AFAt,
		Deco,
		DrCp,
		LisA,
		TabS,
		TocA,
	};
	Type base_type = Type::Unknown;

	bool   Enbl;
	CoDe*  SDlt;
	string SNam;
};

struct BaseExport
{
	enum class Type
	{
		Unknown,
		EOEp,
		EOGf,
		EOHD,
		EOJp,
		EOPS,
		EOPd,
		EOPn,
		EOSv,
		EOTf,
		EOTg,
		EOXR,
		FExO,
	};
	Type base_type = Type::Unknown;

	bool         Bled;
	EnumT        Comp;
	bool         EmIP;
	bool         EmMt;
	struct ICCP* ICCP;
	RGBA*        Matt;
	uint16_t     PlSz;
	EnumT        PlTy;
	bool         Plts;
	EnumT        PxFm;
	EnumT        RaPo;
	EnumT        Rsmp;
	bool         TxCr;
	void*        UPlt;
	bool         ahcl;
	double       dadi;
	bool         isct;
	bool         isds;
	bool         iurd;
	bool         jpeg;
	double       rdpi;
};

struct BaseExVals
{
	enum class Type
	{
		Unknown,
		ExV2,
		ExVI,
		ExVR,
	};
	Type base_type = Type::Unknown;
};

struct BaseScObjs
{
	enum class Type
	{
		Unknown,
		ScAN,
		ScIN,
		ScRN,
	};
	Type base_type = Type::Unknown;

	bool  AAtC;
	bool  ArtC;
	bool  CArC;
	EnumT Dire;
	bool  Prev;
	bool  frnt;
	EnumT nclt;
	/* v_3DLA*, BCRA*, BWRA*, CBRA*, CMRA*, CrRA*, ExRA*, GrRA*, Grup*, HsRA*, ImgN*, InRA*, LeRA*, MRst*, OCRN*, PCrv*, PfRA*, PoRA*,
	 * RcRA*, Rstr*, SCRA*, SHRA*, SPRA*, Scop*, ShpN*, SpTA*, ThRA*, TxtA*, VbRA*, WBRA* */
	BaseLayer* node;
	/* Grup*, Scop*, ShpN*, Sprd*, WBRA* */
	BaseLayer* pnde;
};

struct BaseSubSel
{
	enum class Type
	{
		Unknown,
		CvHS,
		TexS,
	};
	Type base_type = Type::Unknown;
};

struct BaseFlDS
{
	enum class Type
	{
		Unknown,
		v_00DS, /* NOLINT(readability-identifier-naming) */
		FlDS,
	};
	Type base_type = Type::Unknown;
};

struct BaseCrf
{
	enum class Type
	{
		Unknown,
		crfA, /* NOLINT(readability-identifier-naming) */
		crfM, /* NOLINT(readability-identifier-naming) */
		crfR, /* NOLINT(readability-identifier-naming) */
		crfT, /* NOLINT(readability-identifier-naming) */
		crfW, /* NOLINT(readability-identifier-naming) */
	};
	Type base_type = Type::Unknown;

	EnumT    kind;
	uint32_t luid;
	uint32_t type;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct v_00DS: public BaseFlDS
{
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct v_3DLA: public BaseLayer
{
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct v_3DLP: public BaseAdjustment
{
	LR3D* Cube;
};

struct AAAC: public BaseCmd
{
};

struct AAMC: public BaseCmd
{
};

struct AARC: public BaseCmd
{
};

struct ACCm: public BaseCmd
{
	struct Sele* OldS;
};

struct ACrt: public BaseProp
{
	string AcKy;
	string AcRs;
};

struct AESC: public BaseCmd
{
	vector<Sprd*> Spds;
};

struct AFAt: public BaseAtt
{
	GStr*   Left;
	int32_t MxWC;
};

struct AOSC: public BaseCmd
{
	vector<void*> OTbl;
	vector<void*> OlTS;
	ObjS*         Styl;
	bool          isDD;
};

struct ARCm: public BaseCmd
{
	bool                     Empt;
	vector<array<double, 4>> InvB;
	bool                     Mask;
	struct Sele*             OldS;
	/* BCRA*, BWRA*, CBRA*, CrRA*, ExRA*, GrRA*, HsRA*, LeRA*, Rstr*, SCRA*, SHRA*, SpTA*, VbRA*, WBRA* */
	BaseLayer* TNod;
};

struct ARFC: public BaseCmd
{
	FilS* Popp;
};

struct AROm: public BaseCmd
{
	void* OldS;
};

struct AbMp: public BaseProp
{
	string AbVl;
};

struct Adjs: public BaseProp
{
	/* v_3DLA*, BCRA*, BWRA*, ExRA*, GrRA*, HsRA*, LeRA*, PoRA*, RcRA*, SHRA*, SPRA*, ThRA*, VbRA*, WBRA* */
	BaseLayer* Adjs;
};

struct ApVs
{
	int32_t Bild;
	string  Date;
	int32_t Majr;
	int32_t Minr;
	string  Plat;
	string  Prod;
	int32_t Revn;
};

struct ArFr: public BaseFrms
{
	EnumT  ArtA;
	double ArtV;
};

struct AstP: public BaseProp
{
	EnumT AstF;
	/* CnsN*, Comp*, Grup*, PCrv*, Rstr*, ShpN* */
	BaseLayer* AstP;
	double     DPI;
};

struct AuFD: public BaseDels
{
};

struct Auth
{
	string   aEml;
	string   aNam;
	string   aUri;
	string   appv;
	uint64_t chks;
	string   devc;
	string   eUri;
	int64_t  epoc;
	int64_t  expr;
	string   hwid;
	EnumT    licn;
	string   osvr;
	int64_t  rrat;
	bool     rrmd;
	EnumT    sess;
	string   tokn;
	int64_t  updT;
	string   user;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct BCP_38: public BaseAdjustment
{
	float Brig;
	float Ctrs;
	bool  Linr;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct BWP_38: public BaseAdjustment
{
	float Blue;
	float Cyan;
	float Gree;
	float Mage;
	float RedC;
	float Yell;
};

struct BCRA: public BaseLayer
{
};

struct BCoA: public BaseCmd
{
	vector<void*> OldP;
};

struct BGrd
{
	Color32 Colr;
	EnumT   Rlto;
	double  Spac;
	double  Strt;
	bool    UGrd;
};

struct BMCO: public BaseCmd
{
	vector<EnumT> OldB;
};

struct BMGO: public BaseCmd
{
	vector<EnumT> OldB;
};

struct BWAA: public BaseCmd
{
	vector<void*> OldP;
};

struct BWRA: public BaseLayer
{
};

struct BevE: public BaseEffect
{
	double Azim;
	EnumT  Beve;
	double Elev;
	/* HSLA*, RGBA* */
	BaseColor* HiCl;
	bool       Invt;
	EnumT      ShBM;
	/* HSLA*, RGBA* */
	BaseColor* ShCl;
	double     ShOp;
};

struct Blck
{
	EmbeddedData Data;
	int32_t      IRct[4];
	int32_t      Rect[4];
};

struct BlnR
{
	CrvD*  AGam;
	double BGam;
	Spln*  SMSp;
};

struct BmRB: public BaseBrush
{
};

struct BrDy
{
	EnumT        DyVM;
	float        DyVa;
	EnumT        DynC;
	EnumT        DynR;
	float        DynV;
	struct Spln* Spln;
};

struct BrGl: public BaseGlys
{
	EnumT HdBk;
};

struct Brus: public BaseProp
{
	/* IBRB*, RRBr*, SRBr* */
	BaseBrush* Brus;
};

struct CASC: public BaseCmd
{
};

struct CBRA: public BaseLayer
{
};

struct CBaA: public BaseCmd
{
	vector<void*> OldP;
};

struct CFPa
{
	EnumT          Algn;
	vector<double> ColW;
	vector<double> GutW;
	double         Padd[4];
};

struct CIPP: public BaseAdjustment
{
	string DesP;
	string SouP;
};

struct CMRA: public BaseLayer
{
};

struct CMTC: public BaseCmd
{
	vector<array<double, 4>> Area;
	bool                     NeeM;
	double                   Rect[4];
	double                   Tran[6];
	EnumT                    TrnT;
};

struct CMYK: public BaseColor
{
	ColorCMYK v_col;
};

struct CPTx: public BaseLayer
{
};

struct CRGl: public BaseCmd
{
	void*        Dlta;
	bool         MkTx;
	struct Sele* OldS;
	bool         PrCr;
	uint64_t     RLen;
	uint64_t     RLoc;
	uint64_t     SLen;
	uint64_t     SLoc;
};

struct ChGl
{
	uint32_t Char;
};

struct ChMA: public BaseCmd
{
	vector<CnMP*> OldP;
};

struct Clar: public BaseCmd
{
};

struct ClrX: public BaseCmd
{
	string OMet;
};

struct Clrt: public BaseCmd
{
	double Strn;
};

struct CmCm: public BaseCmd
{
};

struct CnMP: public BaseAdjustment
{
};

struct CnsN: public BaseLayer
{
};

struct CoBP: public BaseAdjustment
{
	float HiCR;
	float HiMG;
	float HiYB;
	float MiCR;
	float MiMG;
	float MiYB;
	bool  PeLu;
	float ShCR;
	float ShMG;
	float ShYB;
};

struct CoCO: public BaseCmd
{
	HSLA*         Colr;
	vector<void*> OldC;
};

struct CoDe
{
	/* AuFD*, DrpD*, FSDe*, GADD*, GAID*, GAOD*, GASD*, OTFD*, PADD*, PAID*, PAOD*, SLAD* */
	vector<BaseDels*> Dels;
	LStr*             LDsc;
};

struct CoFr: public BaseFrms
{
	EnumT          Algn;
	vector<double> ColW;
	vector<double> GutW;
	double         Padd[4];
};

struct ColO: public BaseEffect
{
};

struct Comp: public BaseLayer
{
};

struct CrPP: public BaseProp
{
	CrpP* Prst;
};

struct CrRA: public BaseLayer
{
};

struct CrSl: public BaseCmd
{
	struct Sele* NSel;
	struct Sele* Osel;
	int32_t      Rect[4];
	bool         SNSl;
	void*        SlPg;
	struct Slic* Slic;
	struct Sprd* Sprd;
};

struct CrpP
{
	bool    Abs;
	double  DPI;
	double  Hght;
	uint8_t Unit;
	double  Wdth;
};

struct CrvD
{
	v_CB3* Data;
};

struct CrvP: public BaseAdjustment
{
	Spln* C1Sp;
	Spln* C2Sp;
	Spln* C3Sp;
	Spln* C4Sp;
	Spln* C5Sp;
	Spln* Mast;
	float Max_; /* NOLINT(readability-identifier-naming) */
	float Min_; /* NOLINT(readability-identifier-naming) */
};

struct CurA: public BaseCmd
{
	vector<void*> OldP;
};

struct CvHS: public BaseSubSel
{
	vector<array<int32_t, 2>> Hdls;
};

struct DCCm: public BaseCmd
{
	EnumT Labl;
};

struct DDFl
{
	FDsc* DBFD;
	GAtt* DGAF;
	GAtt* DGA_; /* NOLINT(readability-identifier-naming) */
	FDsc* DPFD;
	FDsc* FBFD;
	FDsc* FPFD;
};

struct DDef
{
	CFPa*          CTFP;
	FDsc*          DBFD;
	BGrd*          DBLG;
	LDsc*          DBLS;
	DFFO*          DFFD;
	GAtt*          DGAF;
	GAtt*          DGA_; /* NOLINT(readability-identifier-naming) */
	LDsc*          DLSD;
	PAtt*          DPAF;
	PAtt*          DPA_; /* NOLINT(readability-identifier-naming) */
	FDsc*          DPFD;
	FDsc*          DTFD;
	DMdf*          DmDf;
	FDsc*          FBFD;
	BGrd*          FBLG;
	LDsc*          FLSD;
	FDsc*          FPFD;
	FDsc*          FTFD;
	vector<DDFl*>  Fill;
	bool           HOvr;
	bool           IgBG;
	bool           IgTW;
	bool           PDFP;
	EnumT          PFAn;
	bool           PFCF;
	uint32_t       PFCT;
	GAtt*          RGAF;
	GAtt*          RGA_; /* NOLINT(readability-identifier-naming) */
	PAtt*          RPAF;
	PAtt*          RPA_; /* NOLINT(readability-identifier-naming) */
	bool           SNPI;
	SNAR*          SNPR;
	void*          TCGA;
	vector<double> TFGW;
	vector<double> TFRC;
	double         TWBo[4];
	TbFt*          TbFm;
};

struct DFFO
{
	vector<void*> FKys;
	vector<void*> Fmts;
};

struct DHis
{
	uint32_t        Posi;
	vector<Rstr*>   RBa1;
	vector<RBMI*>   RBa3;
	vector<int32_t> RBaC;
	int32_t         SSHi;
	vector<DcHI*>   Stac;
};

struct DMdf
{
	int32_t colm;
	EnumT   frcr;
	double  gutt;
	bool    lcfr;
	int32_t rcof;
	int32_t rows;
	int32_t rprc;
};

struct DNCm: public BaseCmd
{
	bool         CntA;
	bool         HasR;
	bool         Ignr;
	struct Sele* OlSe;
	/* ShpN*, Sprd* */
	vector<BaseLayer*> OldP;
	bool               SFEM;
	bool               Vald;
};

struct DPOp: public BaseProp
{
	EnumT   Frmt;
	EnumT   PPTy;
	double  bldB;
	double  bldL;
	double  bldR;
	double  bldT;
	bool    cArt;
	bool    dblS;
	double  dpiV;
	bool    face;
	double  hght;
	string  iccP;
	EnumT   imgP;
	bool    incM;
	double  marB;
	double  marL;
	double  marR;
	double  marT;
	bool    tran;
	uint8_t unit;
	double  vDPI;
	bool    vert;
	double  wdth;
};

struct DPro: public BaseCmd
{
	vector<void*>            APCs;
	void*                    APgC;
	void*                    AssC;
	bool                     AssF;
	vector<void*>            BDCs;
	ForC*                    ConC;
	vector<void*>            DPCs;
	void*                    DPgC;
	int32_t                  FPSc;
	bool                     FPag;
	vector<double>           GdsH;
	vector<double>           GdsV;
	bool                     LftS;
	vector<void*>            MDCs;
	void*                    MPCC;
	vector<void*>            MPCs;
	void*                    NBFl;
	double                   NDPI;
	EnumT                    NFor;
	double                   NHht;
	bool                     NIMr;
	EnumT                    NIRP;
	vector<void*>            NMFl;
	vector<array<double, 4>> NMar;
	vector<bool>             NPMr;
	bool                     NPor;
	ICCP*                    NPro;
	bool                     NRet;
	vector<void*>            NSBm;
	bool                     NSHi;
	bool                     NTrn;
	uint8_t                  NUnt;
	double                   NVDP;
	double                   NWid;
	vector<array<double, 6>> NewT;
	void*                    OBBR;
	void*                    OBFl;
	double                   ODPI;
	bool                     OFPg;
	EnumT                    OFor;
	double                   OHht;
	bool                     OIMr;
	EnumT                    OIRP;
	bool                     OLfS;
	vector<void*>            OMFl;
	vector<array<double, 4>> OMar;
	vector<bool>             OPMr;
	bool                     OPor;
	ICCP*                    OPro;
	bool                     ORet;
	vector<void*>            OSBm;
	bool                     OSHi;
	bool                     OTrn;
	uint8_t                  OUnt;
	double                   OVDP;
	bool                     OVSt;
	double                   OWid;
	EnumT                    Resa;
	vector<void*>            RsCs;
	bool                     RsRN;
	void*                    SMPC;
	vector<void*>            TfCs;
	uint32_t                 Type;
	bool                     VStk;
	EnumT                    achT;
	double                   nbld[4];
	double                   obld[4];
};

struct DcHI
{
	/* AAAC*, AAMC*, AARC*, ACCm*, AESC*, AOSC*, ARCm*, CRGl*, ChMA*, CmCm*, CrSl*, DCCm*, DNCm*, DPro*, EnBE*, EnCO*, EnGA*, EnGO*, EnIS*,
	 * EnIg*, EnOg*, EnPB*, EnSh*, EnSt*, ExIn*, FAFH*, FFCm*, FTFH*, FmTC*, GrMA*, GrNC*, InGl*, MC2C*, MvNC*, SBMC*, SDeC*, SLsC*, SSNS*,
	 * SSaC*, SViC*, SetE*, TrCm*, TrSl*, UANC*, XMgC*, XStC* */
	BaseCmd*      Cmnd;
	vector<Futr*> Futu;
	BinaryData    Thum;
	uint64_t      Tim2;
};

struct DcMD
{
	vector<int32_t>          AFIF;
	vector<array<double, 4>> AFRS;
	vector<int32_t>          AFSl;
	string                   Auth;
	string                   COC_; /* NOLINT(readability-identifier-naming) */
	string                   Cmnt;
	int64_t                  CrDt;
	string                   ExpB;
	string                   FlNm;
	string                   FocB;
	string                   FocD;
	string                   FocM;
	string                   FocP;
	string                   FocV;
	string                   HypF;
	string                   ISOE;
	string                   Lens;
	string                   MfBy;
	string                   Path;
	int64_t                  PtDt;
	string                   Revn;
	string                   SMBy;
	string                   Subj;
	int32_t                  SvCt;
	int64_t                  SvDt;
	string                   Tags;
	string                   Titl;
	string                   XMPD;
};

struct DeSy
{
	bool  AAtC;
	bool  ArtC;
	bool  CArC;
	EnumT Dire;
	/* Grup*, PCrv*, Rstr*, Scop*, ShpN* */
	vector<BaseLayer*> Fir1;
	vector<void*>      Fir2;
	vector<ShpN*>      Fir3;
	/* Grup*, PCrv*, Rstr*, Scop*, ShpN* */
	vector<BaseLayer*> Fir4;
	vector<void*>      Fir5;
	/* Grup*, PCrv*, Rstr*, Scop*, ShpN* */
	vector<BaseLayer*> Fir6;
	/* Grup*, PCrv*, Rstr*, Scop*, ShpN* */
	vector<BaseLayer*> Fir7;
	vector<PCrv*>      Fir8;
	vector<void*>      Fir9;
	/* Grup*, PCrv*, Scop*, ShpN* */
	vector<BaseLayer*> Fr10;
	/* Grup*, PCrv*, Scop*, ShpN* */
	vector<BaseLayer*> Fr11;
	/* Grup*, PCrv*, Scop*, ShpN* */
	vector<BaseLayer*> Fr12;
	/* Grup*, PCrv*, Rstr*, Scop*, ShpN* */
	vector<BaseLayer*> Fr13;
	/* Grup*, PCrv*, Rstr*, Scop*, ShpN* */
	vector<BaseLayer*> Fr14;
	/* Grup*, PCrv*, Rstr*, Scop*, ShpN* */
	vector<BaseLayer*> Fr15;
	vector<void*>      Fr16;
	vector<void*>      Fr17;
	/* PCrv*, ShpN* */
	vector<BaseLayer*> Fr18;
	/* Grup*, PCrv*, Rstr*, Scop*, ShpN* */
	vector<BaseLayer*> Fr19;
	/* Grup*, PCrv*, Rstr*, Scop*, ShpN* */
	vector<BaseLayer*> Fr21;
	/* Grup*, PCrv*, Rstr*, Scop*, ShpN* */
	vector<BaseLayer*> Fr22;
	/* PCrv*, ShpN* */
	vector<BaseLayer*> Fr23;
	/* Grup*, PCrv*, Rstr*, Scop*, ShpN* */
	vector<BaseLayer*> Fr24;
	vector<void*>      Fr25;
	/* PCrv*, ShpN* */
	vector<BaseLayer*> Fr26;
	vector<void*>      Fr27;
	vector<void*>      Fr28;
	/* Scop*, ShpN*, Sprd* */
	BaseLayer*     Layr;
	bool           Prev;
	vector<void*>  RDDC;
	vector<void*>  RDGN;
	vector<void*>  RDMC;
	vector<PSRe*>  Sc10;
	vector<PSRe*>  Sc11;
	vector<PSRe*>  Sc12;
	vector<PSRe*>  Sc13;
	vector<PSRe*>  Sc14;
	vector<PSRe*>  Sc15;
	vector<void*>  Sc16;
	vector<void*>  Sc17;
	vector<PSRe*>  Sc18;
	vector<PSRe*>  Sc19;
	vector<PSRe*>  Sc21;
	vector<PSRe*>  Sc22;
	vector<PSRe*>  Sc23;
	vector<PSRe*>  Sc24;
	vector<void*>  Sc25;
	vector<PSRe*>  Sc26;
	vector<void*>  Sc27;
	vector<void*>  Sc28;
	vector<PSRe*>  Sec1;
	vector<void*>  Sec2;
	vector<PSRe*>  Sec3;
	vector<PSRe*>  Sec4;
	vector<void*>  Sec5;
	vector<PSRe*>  Sec6;
	vector<PSRe*>  Sec7;
	vector<PSRe*>  Sec8;
	vector<void*>  Sec9;
	struct Sele*   Sele;
	vector<void*>  UDGN;
	vector<void*>  UDMC;
	vector<void*>  UDNC;
	bool           cnmi;
	bool           dtid;
	vector<void*>  lnkd;
	vector<void*>  mapo;
	vector<string> olgd;
	bool           slcr;
	vector<void*>  ulkd;
	EnumT          unrc;
};

struct DecP
{
	FDsc*   BruS;
	bool    CmBx;
	double  Indt[4];
	LDsc*   LinS;
	int32_t Mask;
	FDsc*   PenS;
	int32_t RBot;
	int32_t RLft;
	int32_t RRgt;
	int32_t RTop;
	FDsc*   Tran;
};

struct Deco: public BaseAtt
{
	vector<DecP*> Deco;
};

struct DocN
{
	void*          AncD;
	uint32_t       BFCr;
	vector<FDsc*>  BFFl;
	BlnR*          BlRa;
	EnumT          Blnd;
	bool           CEdb;
	EnumT          CLiT;
	vector<Sprd*>  Chld;
	DcMD*          DCMD;
	float          DORT;
	vector<DocS*>  DSec;
	void*          Data;
	string         DefD;
	string         Desc;
	double         DfSz[2];
	vector<void*>  DmSt;
	bool           Edtb;
	float          FOpc;
	FTXR*          FTxR;
	bool           FcPa;
	vector<void*>  FiEf;
	vector<string> Frst;
	EnumT          HyTr;
	string         Hypr;
	EnumT          Hyty;
	struct Indx*   Indx;
	uint32_t       LICr;
	vector<FDsc*>  LIFl;
	vector<LDsc*>  LILn;
	bool           LPSt;
	bool           MEtb;
	vector<Sprd*>  MpCh;
	float          Opac;
	BGrd*          Opts;
	bool           PasT;
	vector<string> Scnd;
	double         SrBx[4];
	double         SrPB[4];
	double         TWBo[4];
	EnumT          TWSt;
	void*          TagC;
	EnumT          TrAn;
	int32_t        TrCn;
	double         TrFP[2];
	bool           TrFV;
	int32_t        TraC;
	vector<VwPD*>  VPts;
	bool           Visi;
	bool           VtSt;
	uint32_t       avin;
};

struct DocS
{
	EnumT    Frmt;
	string   Name;
	int32_t  NbFr;
	uint32_t StId;
};

struct DrCp: public BaseAtt
{
	int32_t Heit;
	bool    Left;
	bool    SDsc;
};

struct DrpD: public BaseDels
{
};

struct Dupl: public BaseCmd
{
	bool          ASnC;
	bool          Link;
	bool          MdSp;
	bool          ObRS;
	struct Sele*  OldS;
	vector<void*> RedL;
	vector<void*> Redo;
	double        Trns[6];
	/* PCrv*, ShpN* */
	vector<BaseLayer*> UndL;
	/* PCrv*, ShpN* */
	vector<BaseLayer*> Undo;
};

struct DyBm: public BaseBitm
{
	EmbeddedData    Bckg;
	int32_t         BmpH;
	int32_t         BmpW;
	bool            DelA;
	EnumT           Frmt;
	vector<Blck*>   Idx1;
	vector<Blck*>   Idx2;
	vector<Blck*>   Idx3;
	vector<Blck*>   Idx4;
	vector<Blck*>   Idx5;
	int32_t         LInf;
	vector<Blck*>   MI1_1;
	vector<Blck*>   MI2_1;
	vector<Blck*>   MI3_1;
	vector<Blck*>   MI4_1;
	vector<Blck*>   MI5_1;
	vector<Blck*>   MI1_2;
	vector<Blck*>   MI2_2;
	vector<Blck*>   MI3_2;
	vector<Blck*>   MI4_2;
	vector<Blck*>   MI5_2;
	vector<Blck*>   MI1_3;
	vector<Blck*>   MI2_3;
	vector<Blck*>   MI3_3;
	vector<Blck*>   MI4_3;
	vector<Blck*>   MI5_3;
	vector<Blck*>   MI1_4;
	vector<Blck*>   MI2_4;
	vector<Blck*>   MI3_4;
	vector<Blck*>   MI4_4;
	vector<Blck*>   MI5_4;
	vector<Blck*>   MI1_5;
	vector<Blck*>   MI2_5;
	vector<Blck*>   MI3_5;
	vector<Blck*>   MI4_5;
	vector<Blck*>   MI5_5;
	vector<Blck*>   MI1_6;
	vector<Blck*>   MI2_6;
	vector<Blck*>   MI3_6;
	vector<Blck*>   MI4_6;
	vector<Blck*>   MI5_6;
	vector<Blck*>   MI1_7;
	vector<Blck*>   MI2_7;
	vector<Blck*>   MI3_7;
	vector<Blck*>   MI4_7;
	vector<Blck*>   MI5_7;
	vector<Blck*>   MI1_8;
	vector<Blck*>   MI2_8;
	vector<Blck*>   MI3_8;
	vector<Blck*>   MI4_8;
	vector<Blck*>   MI5_8;
	vector<Blck*>   MI1_9;
	vector<Blck*>   MI2_9;
	vector<Blck*>   MI3_9;
	vector<Blck*>   MI4_9;
	vector<Blck*>   MI5_9;
	vector<Blck*>   MI1_10;
	vector<Blck*>   MI2_10;
	vector<Blck*>   MI3_10;
	vector<Blck*>   MI4_10;
	vector<Blck*>   MI5_10;
	vector<Blck*>   MI1_11;
	vector<Blck*>   MI2_11;
	vector<Blck*>   MI3_11;
	vector<Blck*>   MI4_11;
	vector<Blck*>   MI5_11;
	vector<Blck*>   MI1_12;
	vector<Blck*>   MI2_12;
	vector<Blck*>   MI3_12;
	vector<Blck*>   MI4_12;
	vector<void*>   MI5_12;
	vector<Blck*>   MI1_13;
	vector<Blck*>   MI2_13;
	vector<Blck*>   MI3_13;
	vector<Blck*>   MI4_13;
	vector<void*>   MI5_13;
	vector<void*>   MI1_14;
	vector<void*>   MI2_14;
	vector<void*>   MI3_14;
	vector<void*>   MI4_14;
	vector<uint8_t> MT1_1;
	vector<uint8_t> MT2_1;
	vector<uint8_t> MT3_1;
	vector<uint8_t> MT4_1;
	vector<uint8_t> MT5_1;
	vector<uint8_t> MT1_2;
	vector<uint8_t> MT2_2;
	vector<uint8_t> MT3_2;
	vector<uint8_t> MT4_2;
	vector<uint8_t> MT5_2;
	vector<uint8_t> MT1_3;
	vector<uint8_t> MT2_3;
	vector<uint8_t> MT3_3;
	vector<uint8_t> MT4_3;
	vector<uint8_t> MT5_3;
	vector<uint8_t> MT1_4;
	vector<uint8_t> MT2_4;
	vector<uint8_t> MT3_4;
	vector<uint8_t> MT4_4;
	vector<uint8_t> MT5_4;
	vector<uint8_t> MT1_5;
	vector<uint8_t> MT2_5;
	vector<uint8_t> MT3_5;
	vector<uint8_t> MT4_5;
	vector<uint8_t> MT5_5;
	vector<uint8_t> MT1_6;
	vector<uint8_t> MT2_6;
	vector<uint8_t> MT3_6;
	vector<uint8_t> MT4_6;
	vector<uint8_t> MT5_6;
	vector<uint8_t> MT1_7;
	vector<uint8_t> MT2_7;
	vector<uint8_t> MT3_7;
	vector<uint8_t> MT4_7;
	vector<uint8_t> MT5_7;
	vector<uint8_t> MT1_8;
	vector<uint8_t> MT2_8;
	vector<uint8_t> MT3_8;
	vector<uint8_t> MT4_8;
	vector<uint8_t> MT5_8;
	vector<uint8_t> MT1_9;
	vector<uint8_t> MT2_9;
	vector<uint8_t> MT3_9;
	vector<uint8_t> MT4_9;
	vector<uint8_t> MT5_9;
	vector<uint8_t> MT1_10;
	vector<uint8_t> MT2_10;
	vector<uint8_t> MT3_10;
	vector<uint8_t> MT4_10;
	vector<uint8_t> MT5_10;
	vector<uint8_t> MT1_11;
	vector<uint8_t> MT2_11;
	vector<uint8_t> MT3_11;
	vector<uint8_t> MT4_11;
	vector<uint8_t> MT5_11;
	vector<uint8_t> MT1_12;
	vector<uint8_t> MT2_12;
	vector<uint8_t> MT3_12;
	vector<uint8_t> MT4_12;
	vector<uint8_t> MT5_12;
	vector<uint8_t> MT1_13;
	vector<uint8_t> MT2_13;
	vector<uint8_t> MT3_13;
	vector<uint8_t> MT4_13;
	vector<uint8_t> MT5_13;
	vector<uint8_t> MT1_14;
	vector<uint8_t> MT2_14;
	vector<uint8_t> MT3_14;
	vector<uint8_t> MT4_14;
	EnumT           MipM;
	ICC*            Prof;
	vector<uint8_t> Sta1;
	vector<uint8_t> Sta2;
	vector<uint8_t> Sta3;
	vector<uint8_t> Sta4;
	vector<uint8_t> Sta5;
	int32_t         TInf;
};

struct EDfP: public BaseAdjustment
{
	double Cent[2];
	double Clar;
	double InFo;
	double RadX;
	double RadY;
	double Radi;
	double Rota;
};

struct EOEp: public BaseExport
{
	bool    MnSz;
	int32_t PSLv;
	int32_t Qlty;
};

struct EOGf: public BaseExport
{
};

struct EOHD: public BaseExport
{
};

struct EOJp: public BaseExport
{
	bool    E2Ph;
	bool    Prog;
	uint8_t Qlty;
};

struct EOPS: public BaseExport
{
	EnumT adju;
	EnumT blnd;
	bool  comp;
	EnumT effc;
	bool  fltn;
	EnumT grad;
	EnumT line;
	bool  smll;
};

struct EOPd: public BaseExport
{
	bool    AAdv;
	bool    CnvI;
	EnumT   CoSp;
	bool    EBok;
	bool    EHyp;
	bool    ELay;
	EnumT   EmFo;
	bool    IPrM;
	bool    OvPB;
	bool    PMCB;
	bool    PMCM;
	bool    PMPI;
	bool    PMRM;
	int32_t Qlty;
	bool    Spot;
	bool    SubF;
};

struct EOPn: public BaseExport
{
};

struct EOSv: public BaseExport
{
	int32_t Qlty;
	bool    arco;
	bool    cutp;
	bool    flat;
	bool    isvb;
	bool    ltxp;
	bool    newl;
};

struct EOTf: public BaseExport
{
	EnumT TifC;
};

struct EOTg: public BaseExport
{
};

struct EOXR: public BaseExport
{
	bool v_32Im;
	bool v_32Ot;
	bool v_32Sp;
	bool CSFF;
	bool IULT;
	bool LyMd;
};

struct EmbC
{
	EmbeddedData EmbC;
	void*        FCac;
	void*        FPro;
	string       File;
	bool         Link;
	EmbeddedData PDFD;
};

struct EmbN: public BaseLayer
{
	int32_t AIdx;
	bool    EmAC;
	EmbC*   EmCn;
	string  EmSp;
	void*   FCac;
	void*   FPro;
	bool    IsMs;
	EnumT   PBBx;
	double  RDPI;
	int32_t SIdx;
	int32_t back;
};

struct EmbR: public BaseBitm
{
	bool    EmAC;
	EmbC*   EmCn;
	string  EmSp;
	EnumT   PBBx;
	bool    PssT;
	int32_t back;
};

struct EnBE: public BaseCmd
{
};

struct EnCO: public BaseCmd
{
};

struct EnGA: public BaseCmd
{
};

struct EnGO: public BaseCmd
{
};

struct EnIS: public BaseCmd
{
};

struct EnIg: public BaseCmd
{
};

struct EnOg: public BaseCmd
{
};

struct EnPB: public BaseCmd
{
};

struct EnSh: public BaseCmd
{
};

struct EnSt: public BaseCmd
{
};

struct ExBB
{
	vector<ExBF*> Chks;
};

struct ExBF
{
	string        FNme;
	string        Foot;
	string        Head;
	EnumT         ORul;
	bool          RtOy;
	vector<Sctn*> Scts;
	EnumT         Srch;
};

struct ExCI: public BaseExCsts
{
	int32_t max;
	int32_t min;
};

struct ExCS
{
	/* ExCI*, ExCt* */
	vector<BaseExCsts*> csts;
};

struct ExCV
{
	ExCS* CSet;
	/* ExV2*, ExVI*, ExVR* */
	vector<BaseExVals*> vals;
};

struct ExCm
{
	/* EOEp*, EOGf*, EOHD*, EOJp*, EOPS*, EOPd*, EOPn*, EOSv*, EOTf*, EOTg*, EOXR* */
	BaseExport*   ExOp;
	vector<Scal*> Scls;
};

struct ExCt: public BaseExCsts
{
};

struct ExEq
{
	string eqtn;
};

struct ExIn: public BaseCmd
{
	bool         Incl;
	vector<bool> Undo;
};

struct ExRA: public BaseLayer
{
};

struct ExRS
{
	Rec* v_1x;
	Rec* v_2x;
	Rec* v_3x;
};

struct ExSc
{
	double Mult;
	double Size;
	EnumT  SzTy;
};

struct ExV2: public BaseExVals
{
	double val[2];
};

struct ExVI: public BaseExVals
{
	int32_t val;
};

struct ExVR: public BaseExVals
{
	double val;
};

struct ExpA: public BaseCmd
{
	vector<void*> OldP;
};

struct ExpP: public BaseAdjustment
{
	float Expo;
	bool  Lega;
};

struct FAFH: public BaseCmd
{
	double        Alph;
	uint32_t      Cont;
	bool          LSSl;
	vector<FDsc*> OldF;
};

struct FDsc: public BaseFill
{
	/* FilB*, FilG*, FilN*, FilS* */
	BaseFill* FDeF;
	double    FDeX[6];
};

struct FExO: public BaseExport
{
	EnumT   BSFm;
	EnumT   FTyp;
	uint8_t Qlty;
};

struct FFCm: public BaseCmd
{
	EnumT BleM;
	/* CMYK*, GRAY*, HSLA*, LABA*, RGBA* */
	BaseColor* Colo;
	bool       Cont;
	double     Poin[2];
	EnumT      SamS;
};

struct FRst: public BaseLayer
{
};

struct FSDe: public BaseDels
{
	int32_t      Flds;
	struct Font* Font;
};

struct FTFH: public BaseCmd
{
	uint32_t      Cont;
	vector<FDsc*> OldF;
	double        tint;
};

struct FTXR
{
	vector<string> lngs;
	vector<string> txts;
};

struct FilB: public BaseFill
{
	DyBm* Bitm;
	EnumT ExtT;
	bool  IgnA;
	EnumT ResT;
};

struct FilG: public BaseFill
{
	struct Grad* Grad;
	EnumT        Type;
	bool         XCor;
};

struct FilN: public BaseFill
{
};

struct FilS: public BaseFill
{
	/* CMYK*, GRAY*, HSLA*, LABA*, Pant*, RGBA*, RegC* */
	BaseColor* Colr;
	bool       RClK;
};

struct Filp: public BaseProp
{
	/* FilG*, FilN*, FilS* */
	BaseFill* FLsc;
};

struct FlDS: public BaseFlDS
{
	string Filn;
};

struct FlRN: public BaseLayer
{
	double CdXf[6];
	/* Clar*, Clrt*, RANC*, RDF2*, RDGC*, RDNC*, RGBC*, RHPC*, RLbC*, RLdC*, RLig*, RUSC*, RVgC* */
	BaseCmd* Filt;
	bool     ProA;
};

struct FlrG: public BaseGlys
{
	int32_t FStr;
	int32_t FiTy;
	int32_t ScBg;
};

struct FmTC: public BaseCmd
{
	/* GASD*, PADS* */
	BaseDels*     Delt;
	bool          IgTX;
	PaAS*         NewP;
	vector<Stop*> OItm;
	PaAS*         OldP;
	SSAS*         OldS;
	EnumT         TDfT;
	bool          UPGE;
	bool          USty;
};

struct FntM
{
	vector<void*> Pair;
};

struct Font
{
	string       Famy;
	bool         Ital;
	struct Pano* Pano;
	string       Post;
	int32_t      Wegt;
	int32_t      Widh;
};

struct ForC: public BaseCmd
{
	ICCP*         NCMY;
	bool          NFrC;
	ICCP*         NIAP;
	ICCP*         NLAB;
	ICCP*         NRGB;
	bool          NTBF;
	TStS*         NTSt;
	vector<void*> NeCB;
	vector<void*> NeCl;
	vector<void*> NeFl;
	EnumT         NewF;
	ICCP*         OCMY;
	ICCP*         OIAP;
	ICCP*         OLAB;
	ICCP*         ORGB;
	TStS*         OTSt;
	vector<DyBm*> OlCB;
	/* HSLA*, RGBA* */
	vector<BaseColor*> OlCl;
	vector<FDsc*>      OlFl;
	vector<GAtt*>      OlGl;
	vector<PAtt*>      OlPr;
	vector<DyBm*>      OldB;
	EnumT              OldF;
};

struct Futr
{
	vector<DcHI*> Itms;
};

struct GADD: public BaseDels
{
	double Valu;
};

struct GAID: public BaseDels
{
	int32_t Valu;
};

struct GAOD: public BaseDels
{
	/* FDsc*, HlkA*, LDsc*, OpAA*, OtAt* */
	BaseFill* Valu;
};

struct GASD: public BaseDels
{
	string Valu;
};

struct GAtt
{
	Font*           DFnt;
	vector<double>  Doub;
	vector<int32_t> Ints;
	/* FDsc*, HlkA*, LDsc*, OpAA*, OtAt* */
	vector<BaseFill*> Objs;
	Font*             RFnt;
	vector<string>    Stri;
};

struct GOFl: public BaseCmd
{
	vector<void*> OldF;
};

struct GOTr: public BaseCmd
{
	vector<void*> OldF;
};

struct GRAY: public BaseColor
{
	ColorGRAY v_col;
};

struct GSSP
{
	/* BrGl*, FlrG*, LLGl*, PgNG* */
	vector<BaseGlys*> Glys;
	string            Utf8;
};

struct GStr
{
	vector<GSSP*> Mixd;
	string        Utf8;
};

struct Gaus: public BaseEffect
{
	bool PrAl;
};

struct GlAR
{
	int32_t Indx;
	GAtt*   Item;
};

struct GlAS
{
	vector<GlAR*> Runs;
};

struct GrMA: public BaseCmd
{
	vector<GraP*> NGOP;
	GraP*         NGPa;
	vector<GrMP*> OldP;
};

struct GrMP: public BaseAdjustment
{
	vector<float> GrCD;
	vector<float> GrPD;
};

struct GrNC: public BaseCmd
{
	Grup*                    Grou;
	bool                     NCmG;
	vector<EnumT>            OlCT;
	vector<array<double, 6>> OlFT;
	struct Sele*             OlSl;
	vector<array<double, 6>> OlTr;
	/* Scop*, Sprd* */
	vector<BaseLayer*> OldP;
	/* Grup*, Rstr* */
	vector<BaseLayer*> OldS;
	bool               RACn;
};

struct GrRA: public BaseLayer
{
	GraP* NAjP;
};

struct GraP
{
	struct Grad* Grad;
};

struct Grad
{
	/* CMYK*, GRAY*, HSLA*, LABA*, Pant*, RGBA* */
	vector<BaseColor*>       Cols;
	vector<array<double, 2>> Posn;
};

struct GrdO: public BaseEffect
{
};

struct Grup: public BaseLayer
{
};

struct HSLA: public BaseColor
{
	ColorHSLA v_col;
};

struct HSSP: public BaseAdjustment
{
	bool          HSV;
	float         HueA;
	vector<float> HueC;
	float         LumA;
	vector<float> LumC;
	vector<float> RngC;
	float         SatA;
	vector<float> SatC;
};

struct HlkA: public BaseFill
{
	void* Data;
};

struct HsRA: public BaseLayer
{
};

struct HslA: public BaseCmd
{
	vector<void*> OldP;
};

struct IBRB: public BaseBrush
{
};

struct ICC
{
	bool  BPCm;
	ICCP* CMYP;
	ICCP* IAPr;
	EnumT Intn;
	ICCP* LABP;
	ICCP* RGBP;
	ICCP* RGUP;
};

struct ICCP
{
	BinaryData Data;
};

struct ILDO
{
	/* PCrv*, ShpN* */
	vector<BaseLayer*> ILOb;
};

struct ILGI
{
	/* CnsN*, Comp*, Grup*, MPIN*, MRst*, PCrv*, Rstr*, Scop*, ShpN*, Sprd*, TxtA*, TxtF* */
	vector<BaseLayer*> ILOb;
};

struct ILSN
{
	/* CnsN*, Comp*, Grup*, MPIN*, MRst*, PCrv*, Rstr*, Scop*, ShpN*, Sprd*, TxtA*, TxtF* */
	vector<BaseLayer*> ILOb;
};

struct ILTI
{
	/* CnsN*, Comp*, Grup*, MRst*, PCrv*, Rstr*, Scop*, ShpN*, TxtA*, TxtF* */
	vector<BaseLayer*> ILOb;
};

struct ILTf
{
	vector<TxFl*> ILOb;
};

struct ImgN: public BaseLayer
{
	void*        DTWa;
	EnumT        ExtT;
	bool         FWrO;
	string       ICCP;
	EmbeddedData Orig;
	EnumT        ResT;
	string       StAu;
	string       StkU;
	string       uPro;
};

struct InGl: public BaseCmd
{
	struct Sele* OldS;
	bool         PrNc;
	bool         TSel;
	bool         Togl;
};

struct InRA: public BaseLayer
{
};

struct Indx
{
	bool          ExpX;
	bool          GpPR;
	bool          InSH;
	string        Lang;
	vector<void*> OrTp;
	string        SAfT;
	string        SAfX;
	string        SBfX;
	string        SBtI;
	string        SBtR;
	string        SSeA;
	string        SSee;
	string        Sort;
	vector<void*> Tpcs;
};

struct InnG: public BaseEffect
{
	bool Cntr;
};

struct InnS: public BaseEffect
{
};

struct LABA: public BaseColor
{
	ColorLABA v_col;
};

struct LDsc: public BaseFill
{
	bool    LDBe;
	int32_t LDSa;
	bool    LDSc;
	LSty*   LDeL;
	CrvD*   LDeP;
	bool    LIAh;
};

struct LLGl: public BaseGlys
{
	int32_t Levl;
};

struct LR3D
{
	EmbeddedData  Blob;
	int32_t       Dime;
	string        Name;
	vector<float> Pxls;
};

struct LStr
{
	string Ctxt;
	string Str_; /* NOLINT(readability-identifier-naming) */
};

struct LSty
{
	/* BmRB*, IBRB*, RRBr* */
	BaseBrush*     Brus;
	curve12_t      Data;
	vector<double> Patn;
	double         Phse;
	double         Wght;
};

struct Layt
{
	/* ArFr*, CoFr* */
	vector<BaseFrms*> Frms;
};

struct LcLs
{
	string         defl;
	vector<string> locK;
	vector<string> locV;
};

struct LeFP: public BaseAdjustment
{
	uint16_t A_; /* NOLINT(readability-identifier-naming) */
	uint16_t B_; /* NOLINT(readability-identifier-naming) */
	float    Dens;
	uint16_t L_; /* NOLINT(readability-identifier-naming) */
	bool     Pres;
};

struct LeRA: public BaseLayer
{
};

struct LevA: public BaseCmd
{
	vector<void*> OldP;
};

struct LevP: public BaseAdjustment
{
	float         Blac;
	vector<float> BlkC;
	vector<float> GamC;
	vector<float> OBlC;
	vector<float> OWhC;
	float         OutB;
	float         OutW;
	float         Whit;
	vector<float> WhtC;
};

struct LigP
{
	RGBA*         AmbC;
	double        Ambi;
	double        BMOp;
	void*         BMap;
	double        Dept;
	double        Diff;
	double        Expo;
	vector<LigS*> Lits;
	bool          ScaX;
	bool          ScaY;
	HSLA*         SpeC;
	double        Spec;
};

struct LigS
{
	double Cent[2];
	RGBA*  Colo;
	double Dist;
	double ICon;
	double OCon;
	double Spin;
	double Tilt;
	EnumT  Type;
};

struct LisA: public BaseAtt
{
	EnumT          Alig;
	GStr*          BulS;
	vector<double> IStr;
	double         ITab;
	double         ITxt;
	int32_t        Id;
	int32_t        Levl;
	EnumT          NFmt;
	GStr*          NumS;
	double         OffY;
	int32_t        ResL;
	EnumT          ResT;
	double         Scal;
	GStr*          Sepr;
	GStr*          Strn;
	int32_t        Strt;
	bool           Tier;
	EnumT          Type;
};

struct LoDO
{
	EnumT           ClSp;
	FntM*           FoMp;
	bool            IFET;
	bool            IsPk;
	EnumT           LoMo;
	int32_t         Page;
	vector<int32_t> Pags;
	curve32_t       ResI;
	bool            TxGr;
	double          dpi;
};

struct MC2C: public BaseCmd
{
	bool                 ClSt;
	bool                 Clos;
	double               Delt[2];
	double               Dlt2[2];
	vector<void*>        OCrv;
	void*                ORCv;
	struct Sele*         OldS;
	bool                 OmLN;
	bool                 SOcr;
	vector<struct Undo*> Undo;
};

struct MPIN: public BaseLayer
{
	uint32_t MPOf;
	uint32_t PgCt;
	uint32_t PgOf;
	EnumT    ScMd;
};

struct MRst: public BaseLayer
{
};

struct MacI
{
	/* AAAC*, ARCm*, AROm*, BCoA*, BMCO*, BMGO*, BWAA*, CBaA*, CMTC*, Clar*, ClrX*, CmCm*, CoCO*, CurA*, Dupl*, EnCO*, EnGO*, ExpA*, FFCm*,
	 * ForC*, GOFl*, GOTr*, GrMA*, HslA*, LevA*, MgDC*, OpCO*, OpGO*, RANC*, RDF2*, RDGC*, RDNC*, RDf2*, REqT*, RGBC*, RLbC*, ROCm*, RUSC*,
	 * RVgC*, SBMC*, SCCM*, SDDC*, SGOC*, SHAA*, SRlC*, SSNS*, STAA*, SecA*, SflP*, VibA*, WBaA* */
	BaseCmd*         Cmd;
	vector<uint64_t> CuN1;
	vector<string>   CuN2;
	bool             Enab;
	vector<uint64_t> FavP;
	vector<void*>    MSpl;
	vector<uint64_t> MUID;
	double           Sprd[4];
};

struct MacP: public BaseProp
{
	struct Macr* Macr;
};

struct Macr
{
	string        Desc;
	vector<MacI*> Macr;
};

struct Matx
{
	int32_t        Cols;
	vector<double> Data;
	int32_t        Rows;
};

struct MgDC: public BaseCmd
{
	void* Cach;
	void* DstN;
	bool  Freq;
	void* OlSi;
	void* OldP;
	void* OldS;
	void* SrcN;
};

struct MvNC: public BaseCmd
{
	EnumT        CLiT;
	vector<bool> DtLF;
	/* Grup*, Rstr*, Scop*, ShpN*, Sprd* */
	vector<BaseLayer*> DtLO;
	bool               FrKA;
	vector<bool>       OlTS;
	vector<EnumT>      OldC;
	/* Grup*, Scop*, ShpN*, Sprd* */
	vector<BaseLayer*> OldP;
	bool               RACt;
	EnumT              Type;
};

struct NGHS
{
	EnumT   mcat;
	EnumT   prst;
	int32_t seli;
	string  temd;
};

struct OCRN: public BaseLayer
{
};

struct OSty: public BaseProp
{
	ObjS* OSty;
};

struct OTFD: public BaseDels
{
	vector<UndR*> Feat;
	LStr*         LDsc;
	bool          cler;
};

struct OTFS
{
	uint32_t Feat;
	int32_t  Valu;
};

struct ObSB
{
	uint32_t      BFCr;
	vector<FDsc*> BFFl;
	/* FDsc*, FilS* */
	BaseFill* BFil;
	EnumT     Cont;
};

struct ObSL
{
	EnumT         Cont;
	uint32_t      LICr;
	vector<FDsc*> LIFl;
	vector<LDsc*> LILn;
	LDsc*         LSty;
	/* FDsc*, FilS* */
	BaseFill* PFil;
};

struct ObST
{
	EnumT Cont;
};

struct ObjS: public BaseLayer
{
	void*   CMYK;
	ObSB*   FBru;
	ObSL*   FLin;
	ObST*   FTra;
	EnumT   Frmt;
	void*   GlyA;
	bool    HsBM;
	bool    HsCn;
	bool    HsDM;
	bool    HsDO;
	bool    HsFE;
	bool    HsPF;
	bool    HsTW;
	bool    HsVi;
	ObSB*   MBru;
	ObSL*   MLin;
	ObST*   MTra;
	bool    OSNE;
	void*   ParA;
	ICCP*   RGBP;
	void*   SNPR;
	int32_t colm;
	EnumT   frcr;
	double  gutt;
	bool    lcfr;
	int32_t rcof;
	int32_t rows;
	int32_t rprc;
};

struct OpAA: public BaseFill
{
	vector<OpAV*> Vals;
};

struct OpAV
{
	string Glyp;
	double Left;
};

struct OpCO: public BaseCmd
{
	double Opac;
};

struct OpGO: public BaseCmd
{
	double Opac;
};

struct OtAt: public BaseFill
{
	vector<OTFS*> Setn;
};

struct OutG: public BaseEffect
{
};

struct PADD: public BaseDels
{
	double Valu;
};

struct PADS: public BaseDels
{
	string Valu;
};

struct PAID: public BaseDels
{
	int32_t Valu;
};

struct PAOD: public BaseDels
{
	/* Deco*, LisA*, TabS* */
	BaseAtt* Valu;
};

struct PAtt
{
	vector<double>  Doub;
	vector<int32_t> Ints;
	/* AFAt*, Deco*, DrCp*, LisA*, TabS*, TocA* */
	vector<BaseAtt*> Objs;
	vector<string>   Stri;
};

struct PBxR
{
	vector<array<double, 4>> rcts;
};

struct PCFl
{
	int64_t  MChk;
	uint32_t MUID;
	uint32_t NUID;
	PTNd*    Root;
	int64_t  UChk;
};

struct PCrv: public BaseLayer
{
	PCrv* MCrM;
};

struct PCvD
{
	v_CB2* CnrD;
	v_CB1* Data;
};

struct PLef
{
	string   DNam;
	string   Name;
	string   ONam;
	uint32_t OUID;
	/* ACrt*, AbMp*, Adjs*, AstP*, Brus*, CrPP*, DPOp*, Filp*, MacP*, OSty*, PTCP*, PfPr*, SGrP*, SPPp*, TExM*, TonP* */
	BaseProp* Prop;
	bool      Sync;
	uint32_t  v_UID;
};

struct PLiA
{
	vector<PLig*> PLis;
};

struct PLig
{
	double Alph;
	double Beta;
	HSLA*  Colo;
};

struct PNoC: public BaseCmd
{
	ICCP*        CMYS;
	void*        DCmd;
	EnumT        Form;
	ICCP*        IA_S;
	ICCP*        LABS;
	double       OCRc[4];
	struct Sele* OSel;
	struct Sele* OldS;
	ICCP*        RGBS;
	void*        TCmd;
	bool         Tagg;
	double       VPRc[4];
};

struct PRNS: public BaseCmd
{
};

struct PSRe
{
	void* FSlv;
	void* Mstr;
};

struct PTCP: public BaseProp
{
	PTCf*                Cnfg;
	vector<struct Prst*> Prst;
};

struct PTCf
{
	EnumT         cfmt;
	ExCS*         cnst;
	vector<PTEq*> eqns;
	bool          rads;
};

struct PTEq
{
	ExEq*    eqtn;
	uint32_t mask;
};

struct PTNd
{
	uint32_t      CIdx;
	uint32_t      CUID;
	vector<PTNd*> Chld;
	string        DNam;
	vector<PLef*> Levs;
	string        Name;
	string        ONam;
	uint32_t      OUID;
	bool          Sync;
	uint32_t      Usge;
	uint32_t      v_UID;
};

struct PTRt
{
	uint32_t NUID;
	PTNd*    Root;
};

struct PaAR
{
	int32_t Indx;
	PAtt*   Item;
};

struct PaAS
{
	vector<PaAR*> Runs;
};

struct PaFr: public BaseFrms
{
	vector<double> Advc;
	vector<double> Ends;
	PCvD*          PCrv;
	vector<bool>   Revr;
	vector<double> Strt;
};

struct Pano
{
	vector<uint8_t> byte;
};

struct Pant: public BaseColor
{
	/* CMYK*, HSLA*, LABA*, RGBA* */
	BaseColor* base;
	bool       ispt;
	string     name;
	RGBA*      srgb;
};

struct PcMn
{
	string        cpth;
	string        path;
	vector<PcRs*> ress;
};

struct PcRs
{
	FlDS* dsrc;
	Font* font;
	bool  inst;
	bool  rest;
	EnumT type;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct Per_42
{
	int32_t       Curr;
	vector<Quad*> Pers;
};

struct Pers
{
	bool    v_32Un;
	bool    BPCm;
	int32_t BlGT;
	bool    CCFm;
	/* Scop*, ShpN*, Sprd* */
	BaseLayer* CLyr;
	ICCP*      CMYP;
	Sele*      CSel;
	bool       ClSp;
	void*      CurS;
	DcMD*      DCMD;
	DDef*      DDFl;
	EnumT      DDRF;
	/* EOJp*, EOPS*, EOPn*, EOSv*, EOTf*, FExO* */
	BaseExport*   DFEO;
	PTRt*         DFll;
	bool          DcSH;
	bool          DmCl;
	DocN*         DocR;
	ExBB*         EBDB;
	bool          EdAL;
	Sprd*         EdRt;
	struct ExRS*  ExRS;
	DHis*         Hist;
	ICCP*         IAPr;
	uint64_t      IRNL;
	EnumT         IRPC;
	int32_t       Indx;
	EnumT         Intn;
	ICCP*         LABP;
	bool          LGui;
	LoDO*         LoOp;
	struct Macr*  Macr;
	ApVs*         NVer;
	string        OCIO;
	string        OCIV;
	ApVs*         OVer;
	void*         PDFB;
	EnumT         PPTy;
	struct PcMn*  PcMn;
	PfPr*         PfPl;
	EnumT         PfTg;
	bool          PrCC;
	bool          PrFC;
	vector<CrvD*> PrPr;
	PTRt*         PrpC;
	/* FilG*, FilN*, FilS* */
	vector<BaseFill*>    RFll;
	ICCP*                RGBP;
	ICCP*                RGUP;
	SRst*                RasS;
	bool                 Rest;
	SnpG*                SGrd;
	Sele*                SlBQ;
	uint8_t              SnUT;
	vector<struct Snap*> Snap;
	vector<GStr*>        SpIg;
	vector<SCRn*>        SprC;
	vector<Grup*>        Symb;
	TBFR*                TFmR;
	TBSO*                TSrO;
	TStS*                TSty;
	uint64_t             TxVO;
	bool                 USnG;
	struct UVCn*         UVCn;
	uint8_t              UntT;
	bool                 VAll;
	bool                 VBlG;
	bool                 VBld;
	bool                 VCGu;
	bool                 VGrd;
	bool                 VGui;
	bool                 VMar;
	bool                 VRul;
	bool                 VSpl;
	bool                 VTxF;
	string               XMPM;
};

struct PfPr: public BaseProp
{
	vector<uint32_t> idsl;
	string           name;
};

struct PfRA: public BaseLayer
{
};

struct PgNG: public BaseGlys
{
	int32_t Type;
};

struct PhgB: public BaseEffect
{
	HSLA*  AmbC;
	double Ambi;
	double Diff;
	double Expo;
	PLiA*  Lits;
	HSLA*  SpeC;
	double Spec;
};

struct PoRA: public BaseLayer
{
};

struct PosP: public BaseAdjustment
{
	int32_t Post;
};

struct Pref
{
	vector<string>  BKey;
	vector<bool>    BVal;
	vector<string>  DKey;
	vector<double>  DVal;
	vector<string>  IKey;
	vector<int32_t> IVal;
	vector<string>  PKey;
	/* IBRB*, RRBr*, SRBr* */
	vector<BaseBrush*> PVal;
};

struct Prst
{
	string Name;
	ExCV*  Vals;
};

struct PthT
{
	string Path;
};

struct Quad
{
	double X0;
	double X1;
	double X2;
	double X3;
	double Y0;
	double Y1;
	double Y2;
	double Y3;
};

struct RANC: public BaseCmd
{
	bool Gaus;
};

struct RBMI
{
	bool    Auth;
	DyBm*   Bitm;
	string  Desc;
	int32_t LOff;
	int32_t TOff;
};

struct RDF2: public BaseCmd
{
};

struct RDGC: public BaseCmd
{
	double Opac;
	double Thre;
};

struct RDNC: public BaseCmd
{
	double BBak;
	double ChrS;
	double LumS;
	bool   UsNR;
};

struct RDf2: public BaseCmd
{
};

struct REqT: public BaseCmd
{
	bool   ADeg;
	string EquX;
	string EquY;
	EnumT  Exte;
	double FacA;
	double FacB;
	double FacC;
	bool   Pola;
};

struct RGBA: public BaseColor
{
	ColorRGBA v_col;
};

struct RGBC: public BaseCmd
{
};

struct RHPC: public BaseCmd
{
};

struct RLbC: public BaseCmd
{
	int32_t Blad;
	double  BlmC;
	double  BlmF;
	double  BlmT;
	double  FSto;
};

struct RLdC: public BaseCmd
{
	double RadX;
	double RadY;
};

struct RLig: public BaseCmd
{
	LigP* lpar;
};

struct ROCm: public BaseCmd
{
	bool  CliS;
	bool  ConO;
	void* OldS;
};

struct RRBr: public BaseBrush
{
};

struct RRFC: public BaseCmd
{
	uint32_t Indx;
	/* FilG*, FilS* */
	BaseFill* Repl;
};

struct RUSC: public BaseCmd
{
	double Fact;
	double Thrs;
};

struct RVgC: public BaseCmd
{
	double Hard;
	double Scal;
	double Shap;
};

struct RcRA: public BaseLayer
{
};

struct Rec
{
	bool    Enbl;
	string  FnPf;
	int16_t Scal;
};

struct RecP: public BaseAdjustment
{
	float RecH;
	float RecL;
	float RecS;
};

struct RegC: public BaseColor
{
};

struct Rstr: public BaseLayer
{
};

struct SBMC: public BaseCmd
{
	EnumT         Blen;
	vector<EnumT> OldB;
	vector<bool>  OldP;
	bool          Pass;
};

struct SCCM: public BaseCmd
{
	bool CCFm;
	bool NCCF;
	bool OCCF;
};

struct SCER: public BaseCmd
{
	bool         ClSl;
	void*        Femc;
	Sprd*        OldR;
	struct Sele* OldS;
	Sprd*        Root;
};

struct SCRA: public BaseLayer
{
};

struct SCRn
{
	void*          AncD;
	int32_t        BitI[4];
	int32_t        BitR[4];
	DyBm*          Bitm;
	EnumT          CLiT;
	int32_t        CMsk;
	void*          Data;
	string         Desc;
	bool           Edtb;
	bool           ExtE;
	double         FOV;
	float          FOpc;
	vector<void*>  FiEf;
	vector<string> Frst;
	double         Lati;
	double         Long;
	bool           MEtb;
	float          Opac;
	EnumT          ProT;
	Per_42*        Psp_42;
	double         Roll;
	vector<string> Scnd;
	double         SrBx[4];
	double         SrPB[4];
	double         TWBo[4];
	EnumT          TWSt;
	void*          TagC;
	EnumT          TrAn;
	int32_t        TrCn;
	double         TrFP[2];
	bool           TrFV;
	void*          Unpr;
	bool           Visi;
	Matx*          WRot;
	uint32_t       avin;
};

struct SCoP: public BaseAdjustment
{
	bool Rela;
};

struct SDDC: public BaseCmd
{
	DDef*   Defs;
	int32_t Mask;
};

struct SDeC: public BaseCmd
{
	bool           Chan;
	string         Desc;
	vector<string> ODes;
};

struct SF2C: public BaseCmd
{
	string         FNam;
	vector<string> Redo;
	vector<string> Undo;
};

struct SGCb
{
	double Azim;
	double Elev;
	double Roll;
};

struct SGOC: public BaseCmd
{
	vector<float> OOpa;
	float         Opac;
};

struct SGrP: public BaseProp
{
	bool  Pixl;
	SnpG* SGrd;
};

struct SHAA: public BaseCmd
{
	vector<void*> OldP;
};

struct SHRA: public BaseLayer
{
};

struct SHiP: public BaseAdjustment
{
	float HigA;
	float ShdA;
};

struct SItm
{
	/* v_3DLA*, BCRA*, BWRA*, CBRA*, CMRA*, CPTx*, CrRA*, ExRA*, GrRA*, Grup*, HsRA*, ImgN*, InRA*, LeRA*, MRst*, OCRN*, PCrv*, PfRA*,
	 * PoRA*, RcRA*, Rstr*, SCRA*, SHRA*, SPRA*, Scop*, ShpN*, SlcP*, Slic*, SpTA*, Sprd*, ThRA*, TxtA*, VbRA*, WBRA* */
	BaseLayer* Objt;
	/* CvHS*, TexS* */
	vector<BaseSubSel*> SubS;
};

struct SLAD: public BaseDels
{
	LisA* LstA;
	void* SubA;
	bool  UpIn;
};

struct SLsC: public BaseCmd
{
	vector<struct LDsc*> LSty;
	struct LSty*         Line;
	int32_t              Mask;
	vector<void*>        OGly;
	vector<FDsc*>        OPen;
};

struct SNAR
{
	int32_t AlnX;
	int32_t AlnY;
	int32_t Base;
	int32_t BndX;
	int32_t BndY;
	bool    FPre;
	bool    IPre;
	double  Offs[2];
	double  Scal;
	int32_t SclT;
};

struct SNEN: public BaseLayer
{
};

struct SNRR: public BaseLayer
{
};

struct SOBE: public BaseCmd
{
	vector<bool> OldS;
	bool         Scal;
};

struct SOCO: public BaseCmd
{
	vector<bool> OldS;
	bool         Scal;
};

struct SOGA: public BaseCmd
{
	vector<bool> OldS;
	bool         Scal;
};

struct SOGO: public BaseCmd
{
	vector<bool> OldS;
	bool         Scal;
};

struct SOIS: public BaseCmd
{
	vector<bool> OldS;
	bool         Scal;
};

struct SOIg: public BaseCmd
{
	vector<bool> OldS;
	bool         Scal;
};

struct SOOg: public BaseCmd
{
	vector<bool> OldS;
	bool         Scal;
};

struct SOPB: public BaseCmd
{
	vector<bool> OldS;
	bool         Scal;
};

struct SOSh: public BaseCmd
{
	vector<bool> OldS;
	bool         Scal;
};

struct SOSt: public BaseCmd
{
	vector<bool> OldS;
	bool         Scal;
};

struct SPPp: public BaseProp
{
	SPst* Shpe;
};

struct SPRA: public BaseLayer
{
};

struct SPst
{
	/* ShCE*, ShCR*, ShCg*, ShCl*, ShCr*, ShDA*, ShDS*, ShHt*, ShNR*, ShPi*, ShPy*, ShSS*, ShSg*, ShSt*, ShTr*, ShTz*, ShpD*, ShpT* */
	BaseShape* Shpe;
};

struct SRBr: public BaseBrush
{
};

struct SRlC: public BaseCmd
{
	string  MNam;
	EnumT   NChL;
	int32_t Offs;
	void*   OldS;
};

struct SRst
{
	void*          AncD;
	int32_t        BitI[4];
	int32_t        BitR[4];
	DyBm*          Bitm;
	BlnR*          BlRa;
	EnumT          Blnd;
	bool           CEdb;
	EnumT          CLiT;
	int32_t        CMsk;
	void*          Data;
	string         DefD;
	string         Desc;
	bool           Edtb;
	bool           ExtE;
	double         FOV;
	float          FOpc;
	double         FTxS[6];
	vector<void*>  FiEf;
	vector<string> Frst;
	EnumT          HyTr;
	string         Hypr;
	EnumT          Hyty;
	double         Lati;
	double         Long;
	bool           MEtb;
	float          Opac;
	bool           PasT;
	EnumT          ProT;
	Per_42*        Psp_42;
	Quad*          Pspv;
	double         Roll;
	vector<string> Scnd;
	double         SrBx[4];
	double         SrPB[4];
	double         TWBo[4];
	EnumT          TWSt;
	void*          TagC;
	EnumT          TrAn;
	int32_t        TrCn;
	double         TrFP[2];
	bool           TrFV;
	int32_t        TraC;
	void*          Unpr;
	bool           Visi;
	Matx*          WRot;
	double         Xfrm[6];
	uint32_t       avin;
};

struct SSAR
{
	int32_t Indx;
	EnumT   Item;
};

struct SSAS
{
	vector<SSAR*> Runs;
};

struct SSFH: public BaseCmd
{
	vector<FDsc*> NewF;
	vector<FDsc*> OldF;
	void*         OldS;
};

struct SSLF: public BaseCmd
{
	vector<FDsc*> NewF;
	vector<FDsc*> OldF;
	void*         OldS;
};

struct SSNS: public BaseCmd
{
	bool         ETxt;
	EnumT        Hint;
	struct Sele* OldS;
	bool         TesC;
};

struct SSaC: public BaseCmd
{
	int32_t       Alig;
	vector<void*> OldS;
};

struct STAA: public BaseCmd
{
	vector<void*> OldP;
};

struct STPa: public BaseAdjustment
{
	float Bala;
	float HlHu;
	float HlSa;
	float ShHu;
	float ShSa;
};

struct SViC: public BaseCmd
{
	vector<bool> OVis;
	bool         Visi;
};

struct ScAN: public BaseScObjs
{
};

struct ScIN: public BaseScObjs
{
	/* Grup*, PCrv*, Rstr*, Scop*, ShpN*, TxtA*, WBRA* */
	BaseLayer* ipnd;
};

struct ScPr: public BaseLayer
{
	bool    AAtC;
	bool    ArtC;
	bool    CArC;
	int32_t DIdx;
	EnumT   Dire;
	bool    GnHT;
	/* ScAN*, ScIN*, ScRN* */
	vector<BaseScObjs*> Objs;
	bool                Prev;
	bool                Prog;
	bool                Stac;
	vector<int32_t>     unbr;
};

struct ScRN: public BaseScObjs
{
	DeSy* dtcm;
	EnumT olct;
	/* Grup*, PCrv*, Rstr*, Scop*, ShpN* */
	BaseLayer* olns;
	/* Grup*, Scop*, ShpN*, Sprd* */
	BaseLayer* olpr;
	EnumT      shdt;
};

struct Scal
{
	struct ExSc* ExSc;
	double       ODPI;
	string       Path;
};

struct Scop: public BaseLayer
{
	/* HSLA*, RGBA* */
	BaseColor* SGNc;
	bool       VExp;
};

struct Sctn
{
	string Body;
	string Foot;
	string Head;
	string LPst;
	string Pst;
	bool   RevO;
};

struct SecA: public BaseCmd
{
	vector<void*> OldP;
};

struct Sele
{
	bool          InRi;
	vector<SItm*> Itms;
	/* Scop*, ShpN*, Sprd* */
	BaseLayer* Layr;
};

struct SetE: public BaseCmd
{
	bool          Edit;
	vector<EnumT> OlDS;
	struct Sele*  OldS;
};

struct SflP: public BaseCmd
{
	vector<bool> OldP;
	bool         Prot;
};

struct ShCE: public BaseShape
{
	float TlAn;
};

struct ShCR: public BaseShape
{
	float TlRP;
	float TlWd;
};

struct ShCg: public BaseShape
{
	float    Hole;
	float    NtSz;
	uint16_t Teth;
	float    TtSz;
};

struct ShCl: public BaseShape
{
	uint16_t Bubl;
};

struct ShCr: public BaseShape
{
	float ArcL;
	float ArcR;
};

struct ShDA: public BaseShape
{
	bool  LLnk;
	float LPr1;
	float LPr2;
	EnumT LSty;
	bool  RLnk;
	float RPr1;
	float RPr2;
	EnumT RSty;
	float Thck;
};

struct ShDS: public BaseShape
{
	float PRad;
};

struct ShHt: public BaseShape
{
	float Sprd;
};

struct ShNR: public BaseShape
{
	bool          AbS_123;
	vector<EnumT> CTyp;
};

struct ShPi: public BaseShape
{
	float AngE;
	float AngS;
};

struct ShPy: public BaseShape
{
	bool Smth;
};

struct ShRN: public BaseLayer
{
};

struct ShRR: public BaseShape
{
};

struct ShSS: public BaseShape
{
	float COut;
};

struct ShSg: public BaseShape
{
	float Angl;
	float Pos0;
	float Pos1;
};

struct ShSt: public BaseShape
{
	float    CrcI;
	float    CrcO;
	float    CrvL;
	float    CrvR;
	bool     Lgcy;
	uint16_t Pntt;
};

struct ShTr: public BaseShape
{
	float Ball;
	float Bend;
	bool  Fixd;
	float Tail;
};

struct ShTz: public BaseShape
{
	float PosL;
	float PosR;
	float PosS;
};

struct Shad: public BaseEffect
{
	bool Knck;
};

struct ShpD: public BaseShape
{
};

struct ShpE: public BaseShape
{
};

struct ShpN: public BaseLayer
{
	int32_t CExR[4];
	double  Orgn[2];
	ShpN*   ShpM;
};

struct ShpT: public BaseShape
{
};

struct SlcP: public BaseLayer
{
	bool EmMd;
	/* EOPn*, FExO* */
	BaseExport*   ExOp;
	bool          InBl;
	bool          Init;
	int32_t       SRct[4];
	vector<Slic*> Slcs;
};

struct Slic: public BaseLayer
{
	int32_t Rect[4];
};

struct Smps
{
	double smPt[2];
	EnumT  smTy;
	bool   smVi;
};

struct Snap
{
	bool    BPCm;
	string  Desc;
	DocN*   Docu;
	Sprd*   EdtR;
	EnumT   Form;
	EnumT   Intn;
	SRst*   RasS;
	TStS*   StyS;
	UVCn*   UniC;
	uint8_t UniT;
};

struct SnpG
{
	bool     AUpA;
	double   Ang0;
	double   Ang1;
	double   AngU;
	double   AspR;
	void*    CRot;
	double   CScl;
	SGCb*    Cube;
	int32_t  Dvs0;
	int32_t  Dvs1;
	int32_t  Dvs2;
	bool     FxAs;
	double   Gut0;
	double   Gut1;
	double   Gut2;
	EnumT    Horz;
	uint32_t IDvs;
	EnumT    Intm;
	EnumT    Mode;
	double   Siz0;
	double   Siz1;
	double   Siz2;
	double   UAsR;
	bool     Unfm;
	EnumT    UpRl;
	EnumT    Vert;
};

struct SoPP: public BaseAdjustment
{
	bool  BPCs;
	EnumT Intn;
	ICCP* Prof;
	bool  SPGC;
};

struct SpRV
{
	vector<SpRe*> Rcts;
};

struct SpRe
{
	double       Rect[4];
	struct Sprd* Sprd;
};

struct SpTA: public BaseLayer
{
};

struct Spln
{
	double         Bnd1;
	double         BndN;
	int32_t        Cnt;
	bool           Linr;
	vector<double> Vals;
};

struct Sprd: public BaseLayer
{
	RGBA*         BgrC;
	void*         BlFl;
	void*         DScl;
	bool          Fcng;
	double        Mrgn[4];
	int32_t       PagC;
	bool          PagD;
	bool          PagF;
	bool          R1st;
	SRst*         Ras2;
	SRst*         RasS;
	struct SlcP*  SlcP;
	double        SprB[4];
	bool          SprT;
	double        UOrg[2];
	vector<VwPD*> VPts;
	double        bled[4];
	vector<Smps*> smps;
};

struct StBl
{
	GlAS* GAtt;
	GStr* Glyp;
	PaAS* PAtt;
};

struct StkN: public BaseLayer
{
	EnumT SOpe;
};

struct Stop
{
	ChGl*  DGly;
	bool   FRgh;
	TexS*  GSel;
	TxtA*  IStr;
	GStr*  LStr;
	EnumT  Lead;
	TexS*  PSel;
	double Posn;
	EnumT  Type;
};

struct Strk: public BaseEffect
{
	EnumT Alig;
	EnumT Ftyp;
};

struct Stry
{
	vector<StBl*> Blok;
	bool          iTab;
};

struct SynC
{
	vector<curve16_t> dscB;
	vector<curve16_t> dscE;
	UnknownStruct16   evtI;
	cibs*             ibnd;
	vector<string>    ignD;
	vector<curve16_t> ignK;
	vector<EnumT>     ignV;
	bool              retB;
	string            retU;
	vector<ascp*>     scpK;
};

struct SynP
{
	vector<pdsi*>     itms;
	vector<curve16_t> uids;
};

struct TBFR
{
	vector<TbFt*> fmts;
};

struct TBSO
{
	bool CsSn;
	bool InHd;
	bool NAWd;
};

struct TCel
{
	EnumT  AliY;
	double Inse[4];
};

struct TCls
{
	vector<TCel*> Cell;
	int32_t       Size[2];
};

struct TEdg
{
	FDsc* Fill;
	LDsc* Line;
};

struct TEds
{
	vector<TEdg*> Edge;
	int32_t       Size[2];
};

struct TExM: public BaseProp
{
	string TExl;
};

struct TMpP
{
	double Blap;
	bool   ConE;
	double Cont;
	bool   CrEn;
	CrvP*  Curv;
	double DRAm;
	bool   DREn;
	double DRRd;
	bool   ExpE;
	double Expo;
	double HigI;
	double LocC;
	bool   SHiE;
	double Satu;
	double ShaI;
	double Strg;
	double Tint;
	double Vibr;
	bool   WhBE;
	double WhiB;
	double Whip;
};

struct TPos
{
	vector<double> MSiz;
	vector<double> Posn;
};

struct TStS
{
	vector<TSty*> Styl;
};

struct TSty
{
	string Base;
	CoDe*  Delt;
	string Foll;
	string Name;
	string Next;
	bool   Show;
	EnumT  Type;
};

struct TabS: public BaseAtt
{
	ChGl*                DecG;
	vector<struct Stop*> Stop;
};

struct Tabl
{
	TEds*  CEdg;
	TPos*  CPos;
	TCls*  Cell;
	double Inst[4];
	TEds*  REdg;
	TPos*  RPos;
	TbFt*  TFmt;
};

struct TbBF
{
	FDsc* Fill;
	LDsc* LSty;
};

struct TbCF
{
	EnumT         AlnY;
	vector<TbBF*> Brds;
	FDsc*         Fill;
	double        Inst[4];
	string        Name;
	string        PSty;
};

struct TbFr: public BaseFrms
{
	struct Tabl* Tabl;
};

struct TbFt
{
	int32_t       Brds[4];
	vector<TbCF*> Clls;
	FDsc*         Fill;
	vector<TbCF*> Fmts;
	double        Inst[4];
	bool          IsDf;
	FDsc*         LFll;
	LDsc*         LSty;
	string        Name;
	int32_t       Size[2];
	double        ppi;
};

struct TexS: public BaseSubSel
{
	bool    SACF;
	int32_t SAnc;
	bool    SCCF;
	int32_t SCar;
	bool    SmSp;
};

struct ThRA: public BaseLayer
{
};

struct ThrP: public BaseAdjustment
{
	float Fals;
	float Thre;
	float True;
};

struct Tmps
{
	vector<temp*>     itms;
	vector<curve16_t> uids;
};

struct TocA: public BaseAtt
{
};

struct TonP: public BaseProp
{
	TMpP* Para;
};

struct TrCm: public BaseCmd
{
	bool                     AjPF;
	bool                     CRas;
	bool                     CorC;
	Dupl*                    DupC;
	bool                     DupN;
	bool                     FTxS;
	bool                     Merg;
	MvNC*                    MovC;
	SpRV*                    NIRe;
	double                   NotT[6];
	vector<array<double, 6>> OFTS;
	SpRV*                    OIRe;
	vector<array<double, 6>> OPCT;
	double                   ORST[6];
	vector<EnumT>            OTAn;
	vector<uint32_t>         OTCn;
	vector<array<double, 6>> OlCT;
	vector<array<double, 6>> OldA;
	void*                    PFPC;
	bool                     PPFP;
	bool                     RArt;
	Sprd*                    RpSd;
	void*                    SCSC;
	void*                    SCsC;
	bool                     TrRS;
	vector<void*>            UpDm;
};

struct TrSl: public BaseCmd
{
	EnumT         Mthd;
	vector<void*> Nods;
	int32_t       Ofst[2];
	vector<Slic*> Slcs;
};

struct TxFU
{
};

struct TxFl
{
	bool HOvr;
	/* CPTx*, TxtA*, TxtF*, TxtT* */
	vector<BaseLayer*> Nods;
	ILTf*              TFLK;
};

struct TxtA: public BaseLayer
{
	double bbox[4];
};

struct TxtF: public BaseLayer
{
	vector<PCrv*> WSCh;
	bool          bflp;
};

struct TxtS: public BaseLayer
{
};

struct TxtT: public BaseLayer
{
};

struct UANC: public BaseCmd
{
	struct Sele* OldS;
};

struct UVCn
{
	int32_t SPxM;
	double  UPPI;
	double  VDPI;
};

struct UnSR
{
	int32_t BegI;
	int32_t EndI;
};

struct UndR
{
	vector<UndR*>            Chil;
	double                   FTxS[6];
	uint32_t                 Fetr;
	Grup*                    Grou;
	vector<void*>            IFTI;
	vector<array<double, 6>> IFTT;
	void*                    IfBD;
	vector<array<double, 6>> IfCT;
	/* MRst*, Rstr* */
	vector<BaseLayer*>       InTI;
	vector<array<double, 6>> InTT;
	DyBm*                    InfB;
	double                   InfF[2];
	double                   InfT[6];
	void*                    NexS;
	/* MRst*, Rstr*, ShpN* */
	BaseLayer*               Node;
	void*                    NwFC;
	vector<void*>            OFTI;
	vector<array<double, 6>> OFTT;
	void*                    OlFC;
	void*                    OrBD;
	vector<array<double, 6>> OrCT;
	/* MRst*, Rstr* */
	vector<BaseLayer*>       OrTI;
	vector<array<double, 6>> OrTT;
	DyBm*                    OrgB;
	double                   OrgF[2];
	double                   OrgT[6];
	Scop*                    Pare;
	int32_t                  Valu;
	double                   Xfrm[6];
};

struct Undo
{
	v_CB5* Off;
	v_CB4* On;
};

struct UniV
{
	int32_t Powr;
	uint8_t UniT;
	double  dVal;
};

struct VbRA: public BaseLayer
{
};

struct VibA: public BaseCmd
{
	vector<void*> OldP;
};

struct VibP: public BaseAdjustment
{
	float Satu;
};

struct VwPD
{
	double   vpCt[2];
	double   vpFr;
	bool     vpIM;
	string   vpPn;
	uint32_t vpSI;
};

struct WBRA: public BaseLayer
{
};

struct WBaA: public BaseCmd
{
	vector<void*> OldP;
};

struct WhBP: public BaseAdjustment
{
	float    WBTi;
	uint16_t WhBV;
	int32_t  WhBa;
};

struct XCfg
{
	vector<ExCm*> Fmts;
	string        Path;
};

struct XMgC: public BaseCmd
{
	FlagsT        Chgs;
	bool          Defs;
	vector<void*> Redo;
	vector<XCfg*> Undo;
};

struct XStC: public BaseCmd
{
	bool          Defs;
	vector<void*> Redo;
	vector<XCfg*> Undo;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct v_CB1
{
	uint8_t       byte;
	vector<v_C1*> list;
	uint32_t      size;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct v_CB2
{
	uint8_t       byte;
	vector<v_C2*> list;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct v_CB3
{
	bool              bool_v;
	uint8_t           byte;
	vector<curve18_t> crvs;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct v_CB4
{
	uint8_t  byte;
	EnumT    enum_v;
	uint32_t int_v;
	double   vecd[2];
	int32_t  veci[2];
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct v_CB5
{
	uint8_t  byte;
	uint32_t int_v;
	double   vcd1[2];
	double   vcd2[2];
	int32_t  vci1[2];
	int32_t  vci2[2];
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct v_C1
{
	bool              bool_v;
	vector<curve18_t> crvs;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct v_C2
{
	vector<uint8_t> byts;
	vector<double>  dbls;
	vector<int32_t> ints;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct ascp
{
	struct icol* icol;
	string       uref;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct bndl
{
	EnumT         alvl;
	curve16_t     buid;
	LcLs*         desc;
	string        eula;
	enty*         head;
	LcLs*         name;
	vector<pack*> pcks;
	vector<bres*> rsrs;
	string        sku_46;
	string        stor;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct bres
{
	LcLs*  name;
	string rurl;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct cibs
{
	vector<curve16_t> Ublk;
	vector<curve24_t> keys;
	/* crfA*, crfM*, crfR*, crfT*, crfW* */
	vector<BaseCrf*> refs;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct crfA: public BaseCrf
{
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct crfM: public BaseCrf
{
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct crfR: public BaseCrf
{
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct crfT: public BaseCrf
{
	LcLs* name;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct crfW: public BaseCrf
{
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct enty
{
	uint64_t      aRev;
	EnumT         alvl;
	string        auth;
	bool          capC;
	bool          capE;
	bool          capM;
	bool          capR;
	curve16_t     euid;
	uint32_t      frmt;
	EnumT         kind;
	LcLs*         name;
	vector<erev*> revs;
	int64_t       time;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct erev
{
	string        auth;
	bool          eqiv;
	vector<pmda*> plds;
	uint64_t      revn;
	int64_t       time;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct icol
{
	vector<bndl*> bdls;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct newD
{
	bool     artb;
	UniV*    bbld;
	UniV*    bmgn;
	EnumT    cfmt;
	int32_t  cprl;
	bool     defM;
	UVCn*    dpi;
	bool     face;
	UniV*    hght;
	EnumT    ippy;
	UniV*    lbld;
	UniV*    lmgn;
	bool     mrgn;
	uint32_t nopg;
	EnumT    pgAr;
	EnumT    pgSO;
	int32_t  prst;
	UniV*    rbld;
	UniV*    rmgn;
	bool     tbkd;
	UniV*    tbld;
	UniV*    tmgn;
	EnumT    type;
	bool     ubld;
	bool     umgn;
	uint8_t  unts;
	UniV*    wdth;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct pack
{
	void*         head;
	string        hint;
	vector<enty*> itms;
	LcLs*         name;
	bool          prdH;
	vector<EnumT> prdL;
	curve16_t     puid;
	string        stor;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct pdsi
{
	BinaryData data;
	EnumT      fmt_46;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct pmda
{
	uint32_t chks;
	string   ctyp;
	string   role;
	uint64_t size;
	string   slug;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct temp
{
	EmbeddedData data;
	EmbeddedData thmb;
};

#pragma pack(pop)

} // namespace AffinityReader::CppModel
#endif /* AFFINITY_CPPSTRUCTS_H */
